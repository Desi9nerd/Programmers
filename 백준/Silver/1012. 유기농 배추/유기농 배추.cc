#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t; //t 테스트 케이스의 개수
int m, n, k; //m 가로길이, n 세로길이, k 위치의 개수

int cnt;

vector<vector<int>> v;
queue<int> Q;

int dirY[4] = { -1, 0, 1 ,0 };
int dirX[4] = { 0, -1, 0 ,1 };

void BFS(int y, int x)
{
	queue<pair<int, int>> Q;
	Q.push({ y, x });

	while (!Q.empty())
	{
		int curY = Q.front().first;
		int curX = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int newY = curY + dirY[i];
			int newX = curX + dirX[i];

			if (0 <= newY && newY < n && 0 <= newX && newX < m)
			{
				// 아직 방문하지 않은 배추 위치
				if (v[newY][newX] == 1)
				{
					v[newY][newX] = 0;
					Q.push({ newY, newX });
				}
			}//if
		}//for
	}//while

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	int x, y;

	while(t--)
	{
		cin >> m >> n >> k;
		
		v.resize(n, vector<int>(m, 0));

		cnt = 0;//필요한 배추흰지렁이 마리 수 초기화

		//배추 위치 입력
		for (int i=0; i<k; i++){
			cin >> x >> y;
			v[y][x] = 1;//배추 위치는 1, 빈칸은 0
			
		}
		
		for(int y = 0; y < n; y++){
			for (int x = 0; x < m; x++) 
			{
				//배추 위치를 발견하면 BFS 실행
				if (v[y][x] == 1)
				{
					cnt++;
					BFS(y, x);
				}
			}
		}

		cout << cnt << "\n";
		v.clear();//행렬 초기화
	}


	return 0;
}