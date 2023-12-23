#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<int>> v(2, vector<int>(n + 1, 0)); // 스티커 점수를 저장할 배열
		vector<vector<int>> dp(2, vector<int>(n + 1, 0)); // dp 배열

		for (int y = 0; y < 2; y++)
			for (int x = 1; x <= n; x++)
				cin >> v[y][x];
		
		dp[0][1] = v[0][1];
		dp[1][1] = v[1][1];

		for (int x = 2; x <= n; x++) {
			for (int y = 0; y < 2; y++) {
				int opposite = (y + 1) % 2; // 현재 행과 다른 행

				// 이전 열에서 선택하지 않은 행의 최대 점수와 현재 스티커 점수를 더함
				dp[y][x] = max({ dp[y][x - 1], dp[opposite][x - 1] + v[y][x], dp[opposite][x - 2] + v[y][x] });
			}
		}
		cout << max(dp[0][n], dp[1][n]) << "\n"; // 두 행 중에서 최대 점수 출력
	}

	return 0;
}