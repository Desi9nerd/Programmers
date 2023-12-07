#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e; // v: 정점의 개수, e: 간선의 개수
int k; // k: 시작 정점
vector<vector<pair<int, int>>> graph;

struct Edge {
	int vertex;
	int cost;
	Edge(int a, int b) {
		vertex = a;
		cost = b;
	}
	
	bool operator<(const Edge& e) const {
		return cost > e.cost;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;
	cin >> k; 
	graph.resize(v + 1);
	int x, y, z;
	for (int i = 0; i < e; i++){
		cin >> x >> y >> z;
		graph[x].push_back({ y, z });
	}

	vector<int> dist(v + 1, 2147000000);

	priority_queue<Edge> pQ;
	pQ.push({ k, 0 });
	dist[k] = 0;
	
	while (!pQ.empty())
	{
		int curV = pQ.top().vertex;
		int curC = pQ.top().cost;
		pQ.pop();

		if (dist[curV] < curC) continue;

		for (int i = 0; i < graph[curV].size(); i++)
		{
			int nextV = graph[curV][i].first;
			int nextC = curC + graph[curV][i].second;

			if (dist[nextV] > nextC) {
				dist[nextV] = nextC;
				pQ.push({ nextV, nextC });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == 2147000000) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}