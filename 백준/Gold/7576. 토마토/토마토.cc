#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n;
vector<vector<int>> v, day;
int totalDays; // 토마토가 모두 익을 때까지의 최소 날짜

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int startY, startX;
	cin >> m >> n;
	v.resize(n, vector<int>(m));
	day.resize(n, vector<int>(m));
	vector<pair<int, int>> startLoc;
	for(int y=0; y < n; y++){
		for (int x = 0; x < m; x++) {
			cin >> v[y][x];
			if(v[y][x]==1){
				startLoc.push_back({ y, x });
			}
		}
	}

	queue<pair<int, int>> Q;
	for(int i=0; i<startLoc.size(); i++)
	{
		Q.push({ startLoc[i].first, startLoc[i].second });
		day[startLoc[i].first][startLoc[i].second] = 0;		
	}

	while(!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for(int i=0; i<4; i++)
		{
			int ny = y + dirY[i];
			int nx = x + dirX[i];

			if (ny < 0 || n <= ny || nx < 0 || m <= nx || v[ny][nx] == -1) continue;

			if (v[ny][nx] == 0 && day[ny][nx] == 0)
			{
				Q.push({ ny, nx });
				v[ny][nx] = 1;
				day[ny][nx] = day[y][x] + 1;

				totalDays = max(totalDays, day[ny][nx]);
			}
		}		
	}
		
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (v[y][x] == 0)
			{
				cout << "-1";
				return 0;
			}
		}
	}

	cout << totalDays;

	return 0;
}