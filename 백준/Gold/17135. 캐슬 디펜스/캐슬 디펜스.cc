#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int N, M, D, res = 0;
vector<int> v;
int A[15][15];
int B[15][15];

int kill() {
    int count = 0;
    int dy[3] = { 0, -1, 0 };
    int dx[3] = { -1,0,1 };
    vector<pair<int, int>> zero;

    for (int k = 0; k < 3; k++) {
        queue<pair<pair<int, int>, int>> q;
        bool check[15][15];

        memset(check, 0, sizeof(check));

        q.push({ { N - 1,v[k] },1 });
        check[N - 1][v[k]] = true;

        while (!q.empty()) {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int c = q.front().second;

            q.pop();

            if (c > D) break;
            if (B[y][x] == 1) {
                zero.push_back({ y,x });
                break;
            }

            for (int i = 0; i < 3; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (check[ny][nx]) continue;

                check[ny][nx] = true;
                q.push({ { ny,nx }, c + 1 });
            }
        }
    }

    for (int i = 0; i < zero.size(); i++) {
        int y = zero[i].first;
        int x = zero[i].second;

        if (B[y][x] == 1) {
            B[y][x] = 0;
            count++;
        }
    }

    return count;
}

bool goEnemy() {
    bool tf = false;

    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            if (B[i][j] == 1) {
                B[i][j] = 0;

                if (i != N - 1) {
                    B[i + 1][j] = 1;
                }

                tf = true;
            }
        }
    }

    return tf;
}

void dfs(int depth) {
    if (v.size() == 3) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                B[i][j] = A[i][j];
            }
        }

        int count = 0;

        while (1) {
            count += kill();
            
            if (!goEnemy()) break;
        }

        res = max(res, count);

        return;
    }

    for (int i = depth; i < M; i++) {
        v.push_back(i);
        dfs(depth + 1);
        v.pop_back();
    }
}

void solution(){
    dfs(0);

    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> D;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    solution();

    return 0;
}