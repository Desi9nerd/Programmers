#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> graph[101];
int visited[101];
int cnt=-1;

void DFS(int x) 
{
	if (visited[x] == 1) return;
	
	else
	{
		visited[x] = 1; // 방문하지 않았다면 방문했다고 표시
		cnt++;
	
		for (int i = 0; i < graph[x].size(); i++)
	    {
	        if (visited[graph[x][i]] == 0) // 방문하지 않았다면
	            DFS(graph[x][i]); // 재귀적으로 방문
	    }
	}
}

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	DFS(1);
	
	printf("%d\n", cnt);
	
	return 0;
}