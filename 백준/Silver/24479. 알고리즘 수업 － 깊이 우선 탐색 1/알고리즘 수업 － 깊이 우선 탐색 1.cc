#include<stdio.h>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0, };
int result[100001];
int cnt = 0;

void DFS(int x) {
	if (visited[x] == 1) {
		return;
	}
	else
	{
		visited[x] = 1; // 방문하지 않았다면 방문했다고 표시
		cnt++;
		result[x] = cnt;
	
		for (int i = 0; i < graph[x].size(); i++)
	    {
	        if (visited[graph[x][i]] == 0) // 방문하지 않았다면
	            DFS(graph[x][i]); // 재귀적으로 방문
	    }
	}
	
}
int main() {
	int n, m, r;
	scanf("%d %d %d", &n, &m, &r);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v); 
		graph[v].push_back(u); 
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	DFS(r);
	
	for (int i = 1; i <= n; i++) {
		printf("%d\n", result[i]);
	}
	
}