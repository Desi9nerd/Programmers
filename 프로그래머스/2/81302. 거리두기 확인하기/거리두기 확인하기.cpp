#include <string>
#include <vector>
#include <queue>
using namespace std;

int dirY[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dirX[8] = { 0, -1, 0, 1, -1, 1, -1, 1 };

vector<int> solution(vector<vector<string>> v) {
    vector<int> answer;

    for (int k = 0; k < v.size(); k++) 
    {
        queue<pair<int, int>> Q;

        for (int y = 0; y < v[0].size(); y++) {
            for (int x = 0; x < 5; x++) {
                if (v[k][y][x] == 'P') Q.push({ y, x });
            }
        }

        bool isRight = true;

        while (!Q.empty()) {
            int y = Q.front().first;
            int x = Q.front().second;
            Q.pop();

            // 상하좌우
            for (int i = 0; i < 4; i++) {
                int ny = y + dirY[i];
                int nx = x + dirX[i];

                if (ny < 0 || v[k].size() <= ny || nx < 0 || 5 <= nx) continue;

                if (v[k][ny][nx] == 'P') {
                    isRight = false;
                    break;
                }
                else if (v[k][ny][nx] == 'O') { // 2칸
                    int nny = ny + dirY[i];
                    int nnx = nx + dirX[i];

                    if (nny < 0 || v[k].size() <= nny || nnx < 0 || 5 <= nnx) continue;

                    if (v[k][nny][nnx] == 'P') {
                        isRight = false;
                        break;
                    }
                }
            }
            // 대각선 4방향
            if (isRight)
            {
                for (int i = 4; i < 8; i++) {
                    int ny = y + dirY[i];
                    int nx = x + dirX[i];

                    if (ny < 0 || v[k].size() <= ny || nx < 0 || 5 <= nx) continue;

                    if (v[k][ny][nx] == 'P') {
                        if (v[k][y][nx] == 'O') {
                            isRight = false;
                            break;
                        }
                        if (v[k][ny][x] == 'O') {
                            isRight = false;
                            break;
                        }
                    }

                    if (isRight == false) break;
                }
            }
        }

        if (isRight) answer.push_back(1);
        else answer.push_back(0);
    }
    
    
    return answer;
}