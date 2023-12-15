#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;

	int aSize = a.size();
	int bSize = b.size();
	vector<vector<int>> dp(aSize + 1, vector<int>(bSize + 1, 0));

	for (int i = 1; i <= aSize; i++) {
		for (int j = 1; j <= bSize; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[aSize][bSize];

	return 0;
}