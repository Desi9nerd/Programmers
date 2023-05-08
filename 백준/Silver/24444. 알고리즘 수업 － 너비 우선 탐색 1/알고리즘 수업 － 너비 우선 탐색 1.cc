#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> graph[100001];
int visited[100001], dis[100001], cnt=1;
queue<int> Q;

int main() {
	int n, m, r, x;
	scanf("%d %d %d", &n, &m, &r);
	
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	Q.push(r);
	visited[r]=1;
	
	while(!Q.empty())
	{
		x=Q.front();
		Q.pop();
		dis[x]=cnt++;
		
		for(int i=0; i<graph[x].size(); i++)
		{
			if(visited[graph[x][i]]==0)
			{
				visited[graph[x][i]]=1;
				Q.push(graph[x][i]);
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		printf("%d\n", dis[i]);
	}
	
	return 0;
}