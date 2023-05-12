#include<iostream>
using namespace std;

int res[10];
int n, m, cnt=0;

void DFS(int x, int y)
{
	if(x==m)
	{
		for(int i=0; i<m; i++)
		{
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	
	else
	{
		for(int i=y; i<=n; i++)
		{	//같은 수가 중복해서 들어가도 되므로 체크하지 않는다. 
			
			res[x]=i;  

			DFS(x+1, i);
		
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	
	DFS(0, 1);

	return 0;
}