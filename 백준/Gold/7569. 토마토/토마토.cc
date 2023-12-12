#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

struct Coor {
	int ht, y, x;
};

int m, n, h;
vector<vector<vector<int>>> v;
queue<Coor> Q;
int ch[101][101][101];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m >> n >> h;
	v.resize(h, vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0; i < h; i++){
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				cin >> v[i][y][x];

				if (v[i][y][x] == 1) { // 값이 1이면 큐에 넣고 ch 표시
					Q.push({ i, y, x });
					ch[i][y][x] = 1;
				}
			}
		}
	}

	while (!Q.empty())
	{	
		Coor cur = Q.front();
		Q.pop();

		if (0 < cur.ht && ch[cur.ht - 1][cur.y][cur.x] == 0 && v[cur.ht - 1][cur.y][cur.x] == 0) {
			v[cur.ht - 1][cur.y][cur.x] = 1;
			ch[cur.ht - 1][cur.y][cur.x] = ch[cur.ht][cur.y][cur.x] + 1;
			Q.push({ cur.ht - 1, cur.y, cur.x });
		}
		if (cur.ht < h - 1 && ch[cur.ht + 1][cur.y][cur.x] == 0 && v[cur.ht + 1][cur.y][cur.x] == 0) {
			v[cur.ht + 1][cur.y][cur.x] = 1;
			ch[cur.ht + 1][cur.y][cur.x] = ch[cur.ht][cur.y][cur.x] + 1;
			Q.push({ cur.ht + 1, cur.y, cur.x });
		}
		
		for (int i = 0; i < 4; i++)  // 4방향에 대해 탐색
		{
			int newH = cur.ht;
			int newY = cur.y + dirY[i];
			int newX = cur.x + dirX[i];

			// 범위를 벗어나거나 상자 값이 -1인 경우는 건너뛰기
			if (newH < 0 || h <= newH || newY < 0 || n <= newY || newX < 0 || m <= newX || v[newH][newY][newX] == -1) continue;

			if (ch[newH][newY][newX] == 0 && v[newH][newY][newX] == 0)
			{
				v[newH][newY][newX] = 1;
				ch[newH][newY][newX] = ch[cur.ht][cur.y][cur.x] + 1;
				Q.push({ newH, newY, newX });
			}
		}
	}

	int maxDay = 0;
	// 상자와 ch 전체를 탐색하여 상자 값이 0인 경우 -1 출력하고 프로그램 종료, 아니면 maxDay 갱신
	for (int i = 0; i < h; i++) {
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) 
			{
				if (v[i][y][x] == 0) {
					cout << "-1\n";
					return 0;
				}
				maxDay = max(maxDay, ch[i][y][x]);
			}
		}
	}

	// maxDay가 1이면 0 출력, 아니면 maxDay-1 출력
	cout << (maxDay == 1 ? 0 : maxDay - 1) << "\n";

	return 0;
}