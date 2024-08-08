#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int n;
vector<vector<int>> W;
vector<vector<int>> dp;

int tsp(int cur, int visited) {
    if (visited == (1 << n) - 1) {
        return W[cur][0] ? W[cur][0] : INF;
    }

    int &ret = dp[cur][visited];
    if (ret != -1) return ret;

    ret = INF;
    for (int next = 0; next < n; next++) {
        if (!(visited & (1 << next)) && W[cur][next] != 0) {
            ret = min(ret, tsp(next, visited | (1 << next)) + W[cur][next]);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    W.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(1 << n, -1));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> W[y][x];
        }
    }

    int answer = tsp(0, 1);
    cout << (answer == INF ? -1 : answer) << endl;

    return 0;
}
