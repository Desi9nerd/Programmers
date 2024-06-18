#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

int n, m;
int startY, startX;
int endY, endX;
int answer;

struct Pos{
	int y, x, wallBreak;
};

queue<Pos> Q;
vector<vector<int>> v;
int ch[1001][1001][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	v.resize(n, vector<int>(m));
	cin >> startY >> startX;
	cin >> endY >> endX;
	startX -= 1; startY -= 1; endX -= 1; endY -= 1;

	for (int y = 0; y < n; y++){
		for (int x = 0; x < m; x++) {
			cin >> v[y][x];
		}
	}

	Q.push({ startY, startX, 0 });
	ch[startY][startX][0] = 1;

	while(!Q.empty())
	{
		int y = Q.front().y;
		int x = Q.front().x;
		int w = Q.front().wallBreak;
		Q.pop();

		if (y == endY && x == endX) {
			cout << ch[y][x][w] - 1;
			return 0;
		}

		for (int i = 0; i < 4; i++){
			int ny = y + dirY[i];
			int nx = x + dirX[i];

			if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;

			if (v[ny][nx] == 1 && w == 0 && ch[ny][nx][1] == 0) {
				Q.push({ ny, nx, 1 });
				ch[ny][nx][1] = ch[y][x][w] + 1;
			}
			else if (v[ny][nx] == 0 && ch[ny][nx][w] == 0){
				Q.push({ ny, nx, w });
				ch[ny][nx][w] = ch[y][x][w] + 1;
			}

		}
	}

	cout << "-1";

	return 0;
}