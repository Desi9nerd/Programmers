#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

queue<pair<int, int>> Q;
int ch[101][101];

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    for (int y = 0; y < maps.size(); y++) {
        for (int x = 0; x < maps[0].size(); x++) 
        {
            int cnt = 0; // 방문지점들의 숫자를 더해주는 변수
            if (maps[y][x] != 'X' && ch[y][x] == 0) 
            {
                Q.push({ y, x }); // 방문지점 Q에 삽입
                ch[y][x] = 1;            // 방문체크
                cnt += maps[y][x] - '0'; // 방문지점 숫자 더하기

                while (!Q.empty())
                {
                    int y = Q.front().first;
                    int x = Q.front().second;
                    Q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int ny = y + dirY[i];
                        int nx = x + dirX[i];

                        if (ny < 0 || maps.size() <= ny || nx < 0 || maps[0].size() <= nx) continue;

                        if (maps[ny][nx] != 'X' && ch[ny][nx] == 0)
                        {
                            Q.push({ ny, nx });
                            ch[ny][nx] = 1;
                            cnt += maps[ny][nx] - '0';
                        }
                    }
                }
                answer.push_back(cnt);
            }
        }
    }
    

    if (answer.empty()) 
        return vector<int>{-1};

	sort(answer.begin(), answer.end());

    return answer;
}