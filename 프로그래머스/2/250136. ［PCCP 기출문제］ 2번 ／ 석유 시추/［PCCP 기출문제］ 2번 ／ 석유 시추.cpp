#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };
int r, c;
int answer = 0;
vector<vector<int>> ch;

// BFS 시행은 독립적이고 각각의 BFS로 얻은 석유 시추량은 서로 맡닿아 있지 않기 때문에 같은 X위치에 석유 매장량을 더해도 된다.
map<int, int> DrillLocation; // key: x 위치, value: 석유 매장량

void BFS(int startY, int startX, const vector<vector<int>>& land)
{
    int oilAmount = 1;
    set<int> xLocation;

    ch[startY][startX] = 1;
    queue<pair<int,int>> Q;
    Q.push({ startY, startX });
    xLocation.insert(startX);

    while (!Q.empty())
    {
        int currY = Q.front().first;
        int currX = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = currY + dirY[i];
            int nx = currX + dirX[i];

            if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
            if (land[ny][nx] == 0) continue; // 석유가 없는 땅 continue;

            if (ch[ny][nx] == 0) {
                ch[ny][nx] = 1;
                Q.push({ ny, nx });
                oilAmount++;
                xLocation.insert(nx);
                //cout << "  (ny, nx) = " << ny << ", " << nx << "\n";
            }
        }
    }

    for (const auto& iter : xLocation) {
        DrillLocation[iter] += oilAmount;
        answer = max(answer, DrillLocation[iter]);
        //cout << "iter = " << iter << ", DrillLocation[" << iter << "] = " << DrillLocation[iter] << "\n";
    }

    //cout << "oilAmount = " << oilAmount << "\n\n";
}

int solution(vector<vector<int>> land) {
    r = land.size();
    c = land[0].size();
    ch.resize(r, vector<int>(c));

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (land[y][x] == 1 && ch[y][x] == 0) { // 석유가 있고 아직 방문하지 않은곳
                //cout << "(y, x) = " << y << ", " << x << "\n";
                BFS(y, x, land);
            }
        }
    }

    return answer;
}