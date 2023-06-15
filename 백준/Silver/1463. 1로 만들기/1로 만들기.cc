#include<iostream>
#include<vector>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> dp(n+1);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) 
			dp[i]=min(dp[i], dp[i / 2] + 1);

		if (i % 3 == 0)
			dp[i]=min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[n];

	return 0;
}
