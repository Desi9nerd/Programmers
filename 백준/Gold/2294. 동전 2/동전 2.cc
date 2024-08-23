#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> coins;
vector<int> dp;
const int INF = 2147000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	coins.resize(n);
	for (int i = 0; i < n; i++){
		cin >> coins[i];
	}

	dp.resize(k + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >= coins[j]){
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}

	dp[k] = dp[k] == INF ? -1 : dp[k];

	cout << dp[k];

	return 0;
}