#include <string>
#include <vector>
#include <queue>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

int answer = -1; // 미로를 빠져나가는데 걸리는 최소 시간

int solution(vector<string> maps) {

    int r = maps.size();
    int c = maps[0].size();

    queue<pair<int, int>> Q;
    queue<pair<int, int>> secondQ;
    vector<vector<int>> ch(r, vector<int>(c, 0));

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (maps[y][x] == 'S') {
                Q.push({ y, x });
                //ch[y][x] = 1;
            }
        }
    }

    int cnt = 0;
    bool bLever = false;
    while (!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dirY[i];
            int nx = x + dirX[i];

            if (ny < 0 || r <= ny || nx < 0 || c <= nx || maps[ny][nx] == 'X') continue;

            if (maps[ny][nx] == 'O' && ch[ny][nx] == 0){
                Q.push({ ny, nx });
                ch[ny][nx] = ch[y][x] + 1;
            }
            else if (maps[ny][nx] == 'E' && ch[ny][nx] == 0) {
                Q.push({ ny, nx });
                ch[ny][nx] = ch[y][x] + 1;
            }
            else if (maps[ny][nx] == 'L' && ch[ny][nx] == 0) {
                secondQ.push({ ny, nx });
                ch[ny][nx] = ch[y][x] + 1;
                cnt = ch[ny][nx];
                //cout << "cnt = " << cnt << "\n";
                bLever = true;
                break;
            }
        }

        if (bLever) break;
    }

    if (bLever == false) return answer;

    fill(ch.begin(), ch.end(), vector<int>(c, 0));
    ch[secondQ.front().first][secondQ.front().second] = cnt;

    bool bArrived = false;
    while (!secondQ.empty()) {
        int y = secondQ.front().first;
        int x = secondQ.front().second;
        secondQ.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dirY[i];
            int nx = x + dirX[i];

            if (ny < 0 || r <= ny || nx < 0 || c <= nx || maps[ny][nx] == 'X') continue;

            if (maps[ny][nx] == 'O' && ch[ny][nx] == 0) {
                secondQ.push({ ny, nx });
                ch[ny][nx] = ch[y][x] + 1;
            }
            else if (maps[ny][nx] == 'S' && ch[ny][nx] == 0) {
                secondQ.push({ ny, nx });
                ch[ny][nx] = ch[y][x] + 1;
            }
            else if (maps[ny][nx] == 'E' && ch[ny][nx] == 0) {
                secondQ.push({ ny, nx });
                ch[ny][nx] = ch[y][x] + 1;
                answer = ch[ny][nx];
                bArrived = true;
                break;
            }
        }

        if (bArrived) break;
    }


    return answer;
}