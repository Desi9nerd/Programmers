#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> graph[100001];
int Dv[100001], Bv[100001];
queue<int> Q;

void DFS(int x)
{
	if (Dv[x]==1) return;
	else
	{
		Dv[x]=1;
		printf("%d ", x);
		
		for(int i=0; i<graph[x].size(); i++)
		{
			if (Dv[graph[x][i]]==0)
				DFS(graph[x][i]);
		}
	}
}

void BFS(int x)
{
	Q.push(x);
	Bv[x]=1;
	
	while(!Q.empty())
	{
		x=Q.front();
		Q.pop();
		printf("%d ", x);
		
		for(int i=0; i<graph[x].size(); i++)
		{
			if(Bv[graph[x][i]]==0)
			{
				Bv[graph[x][i]]=1;
				Q.push(graph[x][i]);
			}
		}
	}
}

int main() {
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	DFS(v);
	printf("\n");
	BFS(v);
		
	return 0;
}