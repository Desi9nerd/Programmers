#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;
	int aSize = a.size(); // 첫번째 주어진 문자열 길이
	int bSize = b.size(); // 두번째 주어진 문자열 길이
	vector<vector<int>> dp(aSize + 1, vector<int>(bSize + 1, 0));

	// LCS를 dp[][] 표 형태로 만들어 LCS의 길이 구하기. dp[aSize][bSize]가 길이 최대값
	for (int i = 1; i <= aSize; i++) {
		for (int j = 1; j <= bSize; j++)
		{
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[aSize][bSize] << "\n";


	// LCS 문자 구하기
	string answer;
	for (int i = aSize; i >= 1; i--) {
		for (int j = bSize; j >= 1; j--)
		{
			if (dp[i][j] == dp[i - 1][j]) { // 바로 위 dp값이 같으면 현재 열 값을 유지
				bSize = j;
				break;
			}
			else if (dp[i][j] == dp[i][j - 1]) continue;
			else
				answer = a[i - 1] + answer;
		}
	}

	cout << answer << "\n";

	return 0;
}