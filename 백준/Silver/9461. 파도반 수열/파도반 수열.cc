#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, n;
	cin >> T;
	while(T--)
	{
		cin >> n;
		vector<long long> dp(101, 0);

		dp[0] = 0;
		dp[1] = dp[2] = dp[3] = 1;
		dp[4] = dp[5] = 2;

		for (int i = 6; i < n + 1; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 5];
		}

		cout << dp[n] << "\n";
	}

	return 0;
}