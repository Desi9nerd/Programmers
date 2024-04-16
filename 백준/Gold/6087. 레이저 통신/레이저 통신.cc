#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

int w, h;
int answer = 987654321;
vector<vector<char>> v;
vector<vector<vector<int>>> ch;
int startY, startX;

struct Info{
	int y, x, dir;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	queue<Info> Q;

	cin >> w >> h;
	v.resize(h, vector<char>(w));
	ch.resize(h, vector<vector<int>>(w, vector<int>(4, -1)));

	bool bStart = false;
	for (int y = 0; y < h; y++){
		for (int x = 0; x < w; x++) {
			cin >> v[y][x];
			if (v[y][x] == 'C' && false == bStart) {
				Q.push({ y, x, 0 });
				Q.push({ y, x, 1 });
				Q.push({ y, x, 2 });
				Q.push({ y, x, 3 });
				ch[y][x][0] = 0;
				ch[y][x][1] = 0;
				ch[y][x][2] = 0;
				ch[y][x][3] = 0;
				startY = y;
				startX = x;
				bStart = true;
			}
		}
	}

	while(!Q.empty())
	{
		int y = Q.front().y;
		int x = Q.front().x;
		int dir = Q.front().dir;
		Q.pop();

		for(int i = 0; i < 4; i++){
			int ny = y + dirY[i];
			int nx = x + dirX[i];
			int ndir = i;

			if (ny < 0 || h <= ny || nx < 0 || w <= nx || v[ny][nx] == '*') continue; // 범위 밖이거나 벽인 경우
			if (ny == startY && nx == startX) continue; // 시작 위치는 지나가지 않기

			if (v[ny][nx] == 'C'){
				if (dir != ndir) // 방향을 튼 경우
					answer = min(answer, ch[y][x][dir] + 1);
				else
					answer = min(answer, ch[y][x][dir]);
				continue;
			}

			if (ch[ny][nx][ndir] == -1 || ch[ny][nx][ndir] > ch[y][x][dir] + (dir != ndir)) {
				Q.push({ ny, nx, ndir });
				ch[ny][nx][ndir] = ch[y][x][dir] + (dir != ndir); // 방향 전환 시 거울 개수 증가
			}
		}
		
	}

	cout << answer;

	return 0;
}