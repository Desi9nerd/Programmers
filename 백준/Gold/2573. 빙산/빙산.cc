#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

struct Info {
	int y, x, h;
};

int n, m;
vector<vector<int>> v;
queue<Info> Q;

void GlacierMelting()
{
	vector<vector<int>> temp = v;
	int T = Q.size();

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) 
		{
			if (v[y][x] > 0)
			{
				int adjOcean = 0;	// 4면 중 인접한 바다 수

				for (int i = 0; i < 4; i++)
				{
					int ny = y + dirY[i];
					int nx = x + dirX[i];

					if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;

					if (v[ny][nx] == 0) {
						adjOcean++;
					}
				}

				temp[y][x] = max(0, v[y][x] - adjOcean);
			}
		}
	}

	v = temp;
}

void BFS(int y, int x, vector<vector<int>>& ch)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	ch[y][x] = 1;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dirY[i];
			int nx = x + dirX[i];

			if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;

			if (v[ny][nx] > 0 && ch[ny][nx] == 0) {
				q.push({ ny, nx });
				ch[ny][nx] = 1;
			}
		}
	}
}

int CountGlacierGroups()
{
	int group = 0;
	vector<vector<int>> ch(n, vector<int>(m));

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) 
		{
			if (v[y][x] > 0 && ch[y][x] == 0)
			{
				BFS(y, x, ch);
				group++;
			}
		}
	}

	return group;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	v.resize(n, vector<int>(m));

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> v[y][x];

			if (v[y][x] != 0) {
				Q.push({ y, x, v[y][x] });
			}
		}
	}

	int answer = 0;

	while (true) 
	{
		int groups = CountGlacierGroups();

		if (groups == 0) 
		{
			answer = 0;
			break;
		}
		else if (groups > 1)
		{
			break;
		}

		GlacierMelting();
		answer++;
	}

	cout << answer;

	return 0;
}