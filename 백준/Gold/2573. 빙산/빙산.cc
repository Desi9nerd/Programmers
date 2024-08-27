#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

struct Info {
	int y, x;
};

int n, m;
vector<vector<int>> v;
queue<Info> Q;

void GlacierMelting()
{
	vector<vector<int>> temp = v;
	queue<Info> updatedQ;

	while(!Q.empty())
	{
		int y = Q.front().y;
		int x = Q.front().x;
		Q.pop();

		int adjOceans = 0;
		for (int i = 0; i < 4; i++){
			int ny = y + dirY[i];
			int nx = x + dirX[i];

			if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;

			if (v[ny][nx] == 0){
				adjOceans++;
			}
		}

		int newHeight = max(0, v[y][x] - adjOceans);
		temp[y][x] = newHeight;

		if (newHeight > 0){
			updatedQ.push({ y, x});
		}
	}

	v = temp;
	Q = updatedQ;
}

void BFS(int y, int x, vector<vector<int>>& ch)
{
	queue<Info> q;
	q.push({ y, x });
	ch[y][x] = 1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dirY[i];
			int nx = x + dirX[i];

			if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;

			if (ch[ny][nx] == 0 && v[ny][nx] > 0){
				q.push({ ny, nx });
				ch[ny][nx] = 1;
			}
		}
	}
}

int CountGlacierGroups()
{
	GlacierMelting();

	vector<vector<int>> ch(n, vector<int>(m, 0));

	int groupCnt = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) 
		{
			if (v[y][x] > 0 && ch[y][x] == 0)
			{
				BFS(y, x, ch);
				groupCnt++;
			}
		}
	}

	return groupCnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	v.resize(n, vector<int>(m));

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> v[y][x];

			if (v[y][x] > 0) {
				Q.push({ y, x });
			}
		}
	}

	int answer = 0;
	while(true)
	{
		answer++;

		int groups = CountGlacierGroups();

		if (groups == 0){
			answer = 0;
			break;
		}
		else if (groups >= 2){
			break;
		}
	}


	cout << answer;

	return 0;
}