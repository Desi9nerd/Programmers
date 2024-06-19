#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][16][16]; // dp[i][w][b]: i번째 선수까지 고려했을 때 w명의 화이트 팀과 b명의 블랙 팀을 만들었을 때의 최대 점수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<pair<int, int>> players;
    int a, b;
    while (cin >> a >> b) {
        players.push_back({a, b});
    }

    int n = players.size();

    // DP 배열 초기화
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 15; j++) {
            for (int k = 0; k <= 15; k++) {
                dp[i][j][k] = 0;
            }
        }
    }

    // DP 진행
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= 15; w++) {
            for (int b = 0; b <= 15; b++) {
                dp[i][w][b] = dp[i-1][w][b]; // i번째 선수를 선택하지 않은 경우
                if (w > 0) {
                    dp[i][w][b] = max(dp[i][w][b], dp[i-1][w-1][b] + players[i-1].first); // 화이트 팀에 i번째 선수를 선택한 경우
                }
                if (b > 0) {
                    dp[i][w][b] = max(dp[i][w][b], dp[i-1][w][b-1] + players[i-1].second); // 블랙 팀에 i번째 선수를 선택한 경우
                }
            }
        }
    }

    cout << dp[n][15][15] << "\n"; // 15명의 화이트 팀과 15명의 블랙 팀을 만들었을 때의 최대 점수

    return 0;
}
