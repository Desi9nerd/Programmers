#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m; //n: 세로, m: 가로
vector<vector<int>> v; // nxm 맵

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

struct Pos{
	int y;
	int x;
	int wallbreak;
};
queue<Pos> Q; // BFS 큐, 각 pair는 (y, x) 좌표
vector<vector<vector<int>>> check;; // 각 위치에서 벽 부셨는지 확인하는 배열

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	v.resize(n+2, vector<int>(m+2));
	check.resize(n + 2, vector<vector<int>>(m + 2, vector<int>(2)));
	for (int y = 1; y <= n; y++) {
		string input;
		cin >> input;
		for (int x = 1; x <= m; x++) {
			v[y][x] = input[x-1] - '0';
		}
	}
	
	Q.push({ 1, 1, 0 }); // 시작점
	check[1][1][0] = 1;

	int answer = 1; // 시작하는 칸도 카운팅

	while(!Q.empty())
	{
		int size = Q.size(); //Q의 사이즈는 계속 변하므로 처음에 변수에 담아서 사용한다.
		for(int i = 0; i < size; i++) //Q 사이즈 만큼 검사
		{
			int y = Q.front().y;
			int x = Q.front().x;
			int w = Q.front().wallbreak;
			Q.pop();

			//최종 도착지에 도착
			if (y == n && x == m)
			{
				cout << answer;
				return 0;
			}

			// 4방향 이동체크 후 이동
			for (int i = 0; i < 4; i++) { 
				int ny = y + dirY[i];
				int nx = x + dirX[i];

				if (ny < 1 || n < ny || nx < 1 || m < nx) continue; //맵 벗어나는 경우

				//이전에 벽을 부순적X, 벽인 경우
				if (v[ny][nx] == 1 && w == 0)
				{
					Q.push({ ny, nx, 1 }); // 새로운 위치 Q에 넣기
					check[ny][nx][1] = 1; //
				}
				//이전에 벽을 부순적X, 벽이 아닌 경우
				else if (v[ny][nx] == 0 && check[ny][nx][w] == 0) {
					Q.push({ ny, nx, w }); // 새로운 위치 Q에 넣기
					check[ny][nx][w] = 1; //		
				}
			}
		}
		
		answer++;
	}

	cout << "-1" << "\n"; //도착지로 이동하는게 불가능한 경우
	
	return 0;
}