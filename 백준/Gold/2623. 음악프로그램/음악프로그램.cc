#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m; // n: 가수의 수, m: 보조 PD의 수
vector<int> v; // 진입차수
vector<vector<int>> graph;

bool isCycle = false;
vector<int> answer;

void TopologySort()
{
	queue<int> Q;

	for(int i = 1; i <= n; i++){
		if(v[i] == 0){ // 진입차수가 0인 가수들부터 시작
			Q.push(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if(Q.empty()){ // 출연 순서를 지정할 수 없는 경우
			isCycle = true;
			return;
		}

		int cur = Q.front();
		Q.pop();
		answer.push_back(cur); // 출연순서 기록

		for(int j = 0; j < graph[cur].size(); j++)
		{
			int next = graph[cur][j]; // 다음 가수
			v[next]--; // 다음 가수의 진입차수 -1.

			if(v[next] == 0){
				Q.push(next);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	v.resize(n + 1);
	graph.resize(n + 1);

	int k; // 보조 PD가 담당한 가수의 수
	for(int i = 0; i < m; i++)
	{
		cin >> k;
		if (k == 0) continue;

		int prev, cur;
		cin >> prev;
		for(int j = 0; j < k-1; j++)
		{
			cin >> cur;
			graph[prev].push_back(cur);
			v[cur]++;

			prev = cur;
		}		
	}
	//for (int i = 0; i < graph.size(); i++) {
	//	for (int j = 0; j < graph[i].size(); j++) {
	//		cout << i << "->" << graph[i][j] << "\n";
	//	}
	//}

	TopologySort();

	if (isCycle) cout << "0";
	else {
		for (int i = 0; i < answer.size(); i++){
			cout << answer[i] << "\n";
		}
	}

	return 0;
}