#include <vector>
#include <queue>
using namespace std;


void BFS(int y, int x, int m, int n)
{
    
}

vector<int> solution(int m, int n, vector<vector<int>> v) {
    
    int dirY[4] = { -1, 0, 1, 0 };
    int dirX[4] = { 0, -1, 0, 1 };

    vector<vector<int>> ch(m, vector<int>(n));
    int NumOfArea = 0;
    int MaxOneArea = 0;
    
    for(int y = 0; y < m; y++){
        for (int x = 0; x < n; x++) {
            if (v[y][x] == 0) continue; // 0인 경우, 색칠하지 않는다.

        	if(ch[y][x] == 0){
                
                queue<pair<int, int>> Q;
                Q.push({ y, x });
                ch[y][x] = 1;

                int cnt = 1;
                while(!Q.empty())
                {
                    int y = Q.front().first;
                    int x = Q.front().second;
                    Q.pop();

                    for (int i = 0; i < 4; i++) {
                        int ny = y + dirY[i];
                        int nx = x + dirX[i];

                        if (ny < 0 || m <= ny || nx < 0 || n <= nx) continue;
                        if (v[ny][nx] != v[y][x]) continue; // 다른영역이면 continue

                        if (ch[ny][nx] == 0){
                            ch[ny][nx] = ch[y][x] + 1;
                            Q.push({ ny, nx });

                            cnt++;
                        }
                    }
                }

                MaxOneArea = max(MaxOneArea, cnt);
                NumOfArea++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = NumOfArea;
    answer[1] = MaxOneArea;

    return answer;
}