#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

int n, m; // n: 정점의 수, m: 간선의 수

vector<vector<int>> dist; // Floyd-Warshall. 시작->끝 최단경로 기록
vector<vector<int>> v;	  // 실제 간선

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	dist.resize(n + 1, vector<int>(n + 1, INF));
	v.resize(n + 1, vector<int>(n + 1, -1));

	// 자기 자신을 연결하는 경우 0으로 기본 설정
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		dist[a][b] = dist[b][a] = min(dist[a][b], c);

		v[a][b] = v[b][a] = max(v[a][b], c);
	}

	// Floyd-Warshall 최단경로 구하기
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	double answer = INF;

	for (int k = 1; k <= n; k++) 
	{
		double longest = 0; // 시작(=k)에서 시작했을때 마지막 간선이 사라지는 시간

		for (int i = 1; i <= n; i++) 
		{
			for (int j = 1; j <= n; j++) 
			{
				double remain = 0;
				if (v[i][j] != -1) { // i 정점과 연결되지 않은 경우
					remain = (double)v[i][j] - ((double)dist[k][j] - (double)dist[k][i]);
				}

				if (remain > 0) { // 0이상이면 아직 선이 다 불타지 않은 경우다
					longest = max(longest, (remain / 2) + (double)dist[k][j]);
				}
			}
		}

		answer = min(answer, longest); // 최초 시작 정점(=k) 기준으로 모든 간선을 태우는 시간 최소값 저장
	}

	cout << fixed;
	cout.precision(1);
	cout << answer << "\n";

	return 0;
}