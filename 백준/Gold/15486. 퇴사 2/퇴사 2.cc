#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> T, P;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	T.resize(n + 1); P.resize(n + 1);
	vector<int> dp(n + 2, 0);

	for (int i = 1; i <= n; i++) {
		cin >> T[i] >> P[i];
	}

	int max_value = 0;
	for (int i = 1; i <= n + 1; i++) {
		max_value = max(max_value, dp[i]);
		if (i + T[i] <= n + 1) {
			dp[i + T[i]] = max(dp[i + T[i]], max_value + P[i]);
		}
	}

	cout << max_value << "\n";

	return 0;
}