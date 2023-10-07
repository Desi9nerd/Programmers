#include<vector>
#include<queue>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

queue<pair<int,int>> Q;
int dist[101][101];

int solution(vector<vector<int> > maps)
{
    Q.push({ 0, 0 }); // 시작점
    dist[0][0] = 1; // 시작

    while(!Q.empty())
    {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++)
        {
            int ny = y + dirY[i];
            int nx = x + dirX[i];

            if (ny < 0 || maps.size() <= ny || nx < 0 || maps[0].size() <= nx || maps[ny][nx] == 0) continue;

            if (maps[ny][nx] == 1 && dist[ny][nx] == 0)
            {
                dist[ny][nx] = dist[y][x] + 1;
                Q.push({ ny, nx });

                if (ny == maps.size() - 1 && nx == maps[0].size() - 1)
                    return dist[ny][nx];
            }
        }
    }

    return -1;
}