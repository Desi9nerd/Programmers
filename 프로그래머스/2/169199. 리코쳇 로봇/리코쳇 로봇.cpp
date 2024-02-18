#include <string>
#include <vector>
#include <queue>
using namespace std;
const int INT_MAX = 2147000000;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

int solution(vector<string> v) {
    int r = v.size();
    int c = v[0].size();

    queue<pair<int, int>> Q;
    vector<vector<int>> ch(r, vector<int>(c, INT_MAX));

    int goalY, goalX;

	for(int y = 0; y < r; y++){
        for (int x = 0; x < c; x++) {
            if(v[y][x] == 'R'){
                Q.push({ y, x });
                ch[y][x] = 0;
            }
            else if(v[y][x] == 'G'){
                goalY = y;
                goalX = x;
            }
        }
    }
    
    while(!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dirY[i];
            int nx = x + dirX[i];

            if (ny < 0 || r <= ny || nx < 0 || c <= nx || v[ny][nx] == 'D') continue;

            int nny = y;
            int nnx = x;
            while(true)
            {
                nny += dirY[i];
                nnx += dirX[i];

                if (nny < 0 || r <= nny || nnx < 0 || c <= nnx || v[nny][nnx] == 'D'){
                    nny -= dirY[i];
                    nnx -= dirX[i];

                    if(ch[nny][nnx] > ch[y][x] + 1){
                        Q.push({ nny, nnx });
                        ch[nny][nnx] = ch[y][x] + 1;
                    }
                    break;
                }
            }
        }
    }


    int answer = ch[goalY][goalX] == INT_MAX ? -1 : ch[goalY][goalX];

    return answer;
}