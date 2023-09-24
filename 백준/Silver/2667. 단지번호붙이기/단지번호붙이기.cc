#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt;
vector<vector<int>> v, ch;
vector<int> house;
queue<pair<int, int>> Q;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };


void BFS(int y, int x)
{
	cnt = 1;
	Q.push({ y, x });
	ch[y][x] = 1;

	while (!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dirY[i];
			int nx = x + dirX[i];

			if (ny < 0 || n <= ny || nx < 0 || n <= nx || v[ny][nx] == 0) continue;

			if (ch[ny][nx] == 0)
			{
				ch[ny][nx] = 1;
				Q.push({ ny, nx });

				cnt++;
			}
		}
	}

	house.push_back(cnt);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n, vector<int>(n));
	ch.resize(n, vector<int>(n));

	string input;
	for (int y = 0; y < n; y++) {
		cin >> input;
		for (int x = 0; x < n; x++) {
			v[y][x] = input[x] - '0';
		}
	}	

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (v[y][x] == 1 && ch[y][x]==0) {
				BFS(y, x);
			}
		}
	}

	sort(house.begin(), house.end());

	cout << house.size() << "\n";
	for (const auto& i : house) {
		cout << i << "\n";
	}

	return 0;
}