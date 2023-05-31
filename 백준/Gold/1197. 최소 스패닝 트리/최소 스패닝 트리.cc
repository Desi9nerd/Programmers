#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;	

int vertex[100001];
 
struct Edge
{
	int v1;
	int v2;
	int cost;
	
	Edge(int a, int b, int c){
		v1=a, v2=b, cost=c;
	}
	
	bool operator<(Edge &b){
		return cost<b.cost;
	}
};
 
int Find(int x)
{
	if(x==vertex[x]) return x;
	
	else return vertex[x]=Find(vertex[x]);
}

void Union(int a, int b)
{
	a=Find(a);
	b=Find(b);
	
	if(a!=b) vertex[a]=b;
}

int main()
{
	vector<Edge> Ed;
	int v, e, res=0;
	scanf("%d %d", &v, &e);	
	
	for(int i=1; i<=v; i++){
		vertex[i]=i;
	}
	
	for(int i=1; i<=e; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		
		Ed.push_back(Edge(a, b, c));
	}
	
	sort(Ed.begin(), Ed.end());
	
	for(int i=0; i<e; i++)
	{
		int fa=Find(Ed[i].v1);
		int fb=Find(Ed[i].v2);
		
		if(fa!=fb)
		{
			res+=Ed[i].cost;
			Union(Ed[i].v1, Ed[i].v2);
		}		
	}
	
	printf("%d\n", res);
	
	return 0;
}
