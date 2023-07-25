#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>>dist;

const int INF = 2147000000 / 2;//최댓값 설정

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	dist.resize(n+1, vector<int>(n+1, INF));//기본값을 최댓값
	int a, b, c;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		if(dist[a][b] > c) 
			dist[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				dist[i][j] = 0;
		}
	}

	for (int k = 1; k <= n; k++) 
	{
		for (int i = 1; i <= n; i++) 
		{
			for (int j = 1; j <= n; j++) 
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	
	for (int start = 1; start <= n; start++) 
	{
		for (int end = 1; end <= n; end++) 
		{
			//값이 최댓값이라는건 바뀐적이 없다는 의미(=길이 없다는 의미)
			if (dist[start][end] == INF)
				cout << "0" << " ";
			else
				cout << dist[start][end] << " ";
		}
		cout << "\n";
	}

	return 0;
}