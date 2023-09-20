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
	int wallbreak; // 벽을 부셨는지 여부 (부셨으면 1 아니면 0)
};
queue<Pos> Q; // BFS 큐, (y, x) 좌표와 벽을 부셨는지 여부를 담음
vector<vector<vector<int>>> check;; // 각 위치에 방문했는지 체크하는 배열

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	v.resize(n+2, vector<int>(m+2));
	check.resize(n + 2, vector<vector<int>>(m + 2, vector<int>(2)));

	//입력을 받아서 맵 구성하기
	for (int y = 1; y <= n; y++) {
		string input;
		cin >> input;
		for (int x = 1; x <= m; x++) {
			v[y][x] = input[x-1] - '0';
		}
	}
	
	Q.push({ 1, 1, 0 }); // 시작점
	check[1][1][0] = 1; // 시작점 방문체크, 마지막 [0]은 벽 부섰는지 체크

	int answer = 1; // 시작하는 칸도 카운팅(문제에서 처음도 카운팅한다고 함)

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

				// 벽인 경우, 이전에 벽을 부순적X (w==0)
				if (v[ny][nx] == 1 && w == 0)
				{
					Q.push({ ny, nx, 1 }); // 새로운 위치 Q에 넣기, 1값을 넣어 벽을 부섰음을 체크
					check[ny][nx][1] = 1; //[1]벽 부순걸 체크, =1로 해당 위치 방문 체크
				}
				// 벽이 아닌 경우, 방문한 적이 없는 경우(check[ny][nx][w]==0)
				else if (v[ny][nx] == 0 && check[ny][nx][w] == 0) {
					Q.push({ ny, nx, w }); // 새로운 위치 Q에 넣기
					check[ny][nx][w] = 1; // =1로  해당 위치 방문 체크		
				}
			}
		}
		
		answer++;
	}

	cout << "-1" << "\n"; //도착지로 이동하는게 불가능한 경우
	
	return 0;
}