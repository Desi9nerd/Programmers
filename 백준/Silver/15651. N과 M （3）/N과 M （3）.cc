#include<iostream>
using namespace std;

int num[10], res[10], ch[10];
int n, m, cnt=0;

void DFS(int x)
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
		for(int i=1; i<=n; i++)
		{	//같은 수가 중복해서 들어가도 되므로 체크하지 않는다. 
			res[x]=i; //주어진 수가 1~n이 아닌 경우는 num[i]사용. 

			DFS(x+1);
		
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	
//	for(int i=1; i<=n; i++){
//		num[i]=i;
//	}
	
	DFS(0);

	return 0;
}