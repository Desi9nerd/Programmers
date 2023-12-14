#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, x; // n: 마을의 수=학생의 수(각각의 마을에 1명씩 거주), m: 단방향 도로 수, x: 파티가 벌어지는 마음(도착 위치)
vector<vector<pair<int, int>>> v(1001);
int result[1001][1001];

struct Edge{
	int city, cost;

	Edge(int a, int b){
		city = a;
		cost = b;
	}

	bool operator<(const Edge& e) const{
		return cost > e.cost;
	}
};

void D(int start, int end) // k: 시작 마을, x: 도착 마을
{
	priority_queue<Edge> pQ;
	pQ.push({ start, 0 }); // 시작 위치

	vector<int> dist(n + 1, 2147000000);
	dist[start] = 0; // 시작 위치 방문

	while (!pQ.empty())
	{
		int curCity = pQ.top().city;
		int curCost = pQ.top().cost;
		pQ.pop();

		if (curCity == end) // 도착
		{
			result[start][end] = dist[end];
			break;
		}

		if (dist[curCity] < curCost) continue;

		for (int i = 0; i < v[curCity].size(); i++)
		{
			int nextCity = v[curCity][i].first;
			int nextCost = curCost + v[curCity][i].second;

			if (dist[nextCity] > nextCost) // 더 적은시간이 걸리는 경로를 발견한 경우
			{
				dist[nextCity] = nextCost; // 해당 경로를 이동하는데 걸리는 비용(시간) 갱신
				pQ.push({ nextCity, nextCost });
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> x;
	int a, b, c;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	for(int k = 1; k <= n; k++) // 시작 위치를 다르게해서 출발. 시작위치(k) -> 도착위치(x)
	{
		D(k, x);
	}

	for (int k = 1; k <= n; k++) // 시작 위치를 다르게해서 출발. 시작위치(x) -> 도착위치(k)
	{
		D(x, k);
	}

	int answer = 0; // 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간
	for(int i = 1; i <= n; i++)
	{
		answer = max(answer, result[i][x] + result[x][i]);
	}

	cout << answer;	

	return 0;
}