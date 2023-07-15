#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, res;
	cin >> n;
	vector<int> v(n), dp(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[0] = 1;
	res = 1;
	for (int i = 1; i < n; i++) 
	{
		int prevDpMax = 0;

		for (int j = i - 1; j >= 0; j--)
		{
			if (v[j] < v[i] && dp[j] > prevDpMax)
			{
				prevDpMax = dp[j];
			}
		}

		dp[i] = prevDpMax + 1;

		if (res < dp[i]) res = dp[i];
	}

	cout << res;

	return 0;
}