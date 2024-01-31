#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

int n, m;
vector<vector<int>> v;
vector<vector<int>> ch, visited_Wall; 

void BFS(int y, int x)
{
	queue<pair<int, int>> Q;
	Q.push({ y, x });
	ch[y][x] = 1;
	int cnt = 1;

	queue<pair<int, int>> wallQ;

	while (!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dirY[i];
			int nx = x + dirX[i];

			if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;

			// 방문한적 없는 0
			if (v[ny][nx] == 0 && ch[ny][nx] == 0) {
				Q.push({ ny, nx });
				ch[ny][nx] = 1;
				cnt++;
			}
			// 방문한적 없는 1(wall). 인접한 wall
			else if (v[ny][nx] >= 1 && visited_Wall[ny][nx] == 0) {
				wallQ.push({ ny, nx });
				visited_Wall[ny][nx] = 1;
			}
		}
	}

	// 인접한 wall에 방금 방문한 0들을 카운트(cnt)한 값을 더함
	while(!wallQ.empty())
	{
		int yy = wallQ.front().first;
		int xx = wallQ.front().second;
		wallQ.pop();

		v[yy][xx] += cnt;
		visited_Wall[yy][xx] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	v.resize(n, vector<int>(m));
	ch.resize(n, vector<int>(m)); 
	visited_Wall.resize(n, vector<int>(m));

	string input;
	for (int y = 0; y < n; y++) {
		cin >> input;
		for (int x = 0; x < m; x++) {
			v[y][x] = input[x] - '0';
		}
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) 
		{
			if (v[y][x] == 0 && ch[y][x] == 0) {
				BFS(y, x);
			}
		}
	}


	// 출력
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cout << v[y][x] % 10;
		}
		cout << "\n";
	}

	return 0;
}