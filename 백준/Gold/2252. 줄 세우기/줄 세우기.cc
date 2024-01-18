#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m; // n: 학생의 수, m: 키를 비교한 횟수
vector<vector<int>> graph;
vector<int> inDegree;
vector<int> result;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m; 
	graph.resize(n+1);
	inDegree.resize(n+1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		inDegree[b]++;
	}

	queue<int> Q;
	// 진입차수가 0인 학생을 모두 담음(=시작 시 담을 학생들)
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			Q.push(i);
		}
	}

	// 위상정렬
	while (!Q.empty())
	{
		int idx = Q.front();
		Q.pop();
		result.push_back(idx);

		// 현재 학생보다 큰 학생으로 명시된 학생들 
		for (int i = 0; i < graph[idx].size(); i++) {
			int next = graph[idx][i];

			inDegree[next]--; // 진입차수 빼기

			if (inDegree[next] == 0) {
				Q.push(next);
			}
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}