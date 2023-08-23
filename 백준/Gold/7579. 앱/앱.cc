#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;

    vector<int> memory(N + 1);
    vector<int> cost(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> memory[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> cost[i];
    }

    int total_cost = 0;
    for (int i = 1; i <= N; ++i) {
        total_cost += cost[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(total_cost + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= total_cost; ++j) {
            if (j >= cost[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int answer = 0;
    for (int j = 0; j <= total_cost; ++j) {
        if (dp[N][j] >= M) {
            answer = j;
            break;
        }
    }

    cout << answer << "\n";

    return 0;
}
