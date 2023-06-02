#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int cost[N][3]; // 집의 색상별 비용을 저장하는 배열
    int dp[N][3];   // dp[i][j]: i번째 집을 j색으로 칠할 때까지의 최소 비용

    // 집의 색상별 비용 입력
    for (int i = 0; i < N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    // 첫 번째 집의 비용은 초기 비용으로 설정
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    // 두 번째 집부터 N번째 집까지 최소 비용 계산
    for (int i = 1; i < N; i++) {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    // N번째 집까지 칠할 때의 최소 비용 중 최솟값 출력
    int result = min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
    cout << result << endl;

    return 0;
}