#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, m;
vector<vector<int>> maze;//주어진 미로
vector<vector<int>> dist;//[y][x] 배열에 도달하기까지의 값

int dirX[4] = { -1, 0, 1, 0 };
int dirY[4] = { 0, -1, 0, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    maze.resize(n + 2, vector<int>(m + 2));
    dist.resize(n + 2, vector<int>(m + 2));

    string input;
    for(int i=1; i<=n; i++){
        cin >> input;
        for(int j=1; j<=m; j++){
            maze[i][j] = input[j - 1] - '0';
        }
    }   


    queue<pair<int, int>> Q;
    Q.push(make_pair(1, 1));//시작점 넣어주기
    dist[1][1] = 1;

    while(!Q.empty())
    {
        pair<int, int> x = Q.front();
        Q.pop();

        //상하좌우 이동 체크 후 적용
        for (int i=0; i<4; i++)
        {
            int newY = x.first + dirY[i];
            int newX = x.second + dirX[i];

            //방문 가능한 곳이면
            //maze가 1인 곳으로만 이동할 수 있다. dist[][]==0 이면 아직 안 가본 칸이라는 의미다.
	        if (maze[newY][newX] == 1 && 
                dist[newY][newX] == 0 &&
                newX > 0 && newY > 0 && newY <= n && newX <= m)
	        {
                Q.push(make_pair(newY, newX));//newY, newX 위치에서 출발하도록 Q에 넣어준다.
                dist[newY][newX] = dist[x.first][x.second] + 1;//거리 +1                
	        }
        }
    }

    cout << dist[n][m];

    return 0;
}