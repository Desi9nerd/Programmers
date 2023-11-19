#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

int n, m; // n: 세로, m: 가로
int safe;
vector<vector<int>> map, v;
vector<pair<int, int>> zero, one, two;
queue<pair<int, int>> Qtwo;
vector<vector<int>> visited;
vector<vector<int>> ch;
vector<bool> Select;

void Calculate()
{
    queue<pair<int, int>> Q;
    Q = Qtwo;
    ch = visited;

    vector<vector<int>> temp = v;

    while (!Q.empty())
    {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dirY[i];
            int nx = x + dirX[i];

            if (ny < 0 || n <= ny || nx < 0 || m <= nx || temp[ny][nx] != 0) continue;

            if (ch[ny][nx] == 0)
            {
                temp[ny][nx] = 2;
                ch[ny][nx] = 1;
                Q.push({ ny, nx });
            }
        }
    }

    int cnt = 0;
    for (int y = 0; y < n; y++){
        for (int x = 0; x < m; x++){
            if (temp[y][x] == 0) cnt++;
        }
    }

    safe = max(safe, cnt);
}

void Combination(int idx, int cnt)
{
    if (cnt == 3) {
        Calculate();
        return;
    }

    for (int i = idx; i < zero.size(); i++)
    {
        if (Select[i] == false)
        {
            Select[i] = true;
            v[zero[i].first][zero[i].second] = 1;
            Combination(i + 1, cnt + 1);
            v[zero[i].first][zero[i].second] = 0;
            Select[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    map.resize(n, vector<int>(m));
    v.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m, 0));
    ch.resize(n, vector<int>(m, 0));
    Select.resize(n * m, false);
    for(int y = 0; y < n; y++){
        for (int x = 0; x < m; x++) {
            cin >> v[y][x];
            map[y][x] = v[y][x];

            if (v[y][x] == 0) 
                zero.push_back({ y, x });
            else if (v[y][x] == 2){
                Qtwo.push({ y, x });
                visited[y][x] = 1;
            } 
        }
    }

    Combination(0, 0);

    cout << safe << "\n";

    return 0;
}
