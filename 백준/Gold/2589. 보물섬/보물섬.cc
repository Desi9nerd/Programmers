#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

int r, c;
vector<vector<char>> v;
int answer;

void BFS(int startY, int startX)
{
	vector<vector<int>> ch(r, vector<int>(c, -1));
	queue<pair<int, int>> Q;
	Q.push({ startY, startX });
	ch[startY][startX] = 0;

	while(!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for(int i = 0; i < 4; i++){
			int ny = y + dirY[i];
			int nx = x + dirX[i];

			if (ny < 0 || r <= ny || nx < 0 || c <= nx || v[ny][nx] == 'W') continue;

			if (ch[ny][nx] == -1 && v[ny][nx] == 'L') {
				Q.push({ ny, nx });
				ch[ny][nx] = ch[y][x] + 1;
				answer = max(answer, ch[ny][nx]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;
	v.resize(r, vector<char>(c));
	for(int y = 0; y < r; y++){
		for (int x = 0; x < c; x++) {
			cin >> v[y][x];
		}
	}

	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			if (v[y][x] == 'L')
				BFS(y, x);
		}
	}

	cout << answer;

	return 0;
}