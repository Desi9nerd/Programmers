#include <stdio.h>
using namespace std;

int n;  
int max=-1000000001;
int min=1000000001;
int a[101], oper[4];

void DFS(int L, int result)
{
	if(L==n)
	{
		if (result > max) max = result;
		if (result < min) min = result;
		return;
	}
	
	for(int i=0; i<4; i++)
	{
		if(oper[i] > 0 )
		{
			oper[i]--;
			if(i==0) DFS(L+1, result+a[L]);
			else if(i==1) DFS(L+1, result-a[L]);
			else if(i==2) DFS(L+1, result*a[L]);
			else if(i==3) DFS(L+1, result/a[L]);
			oper[i]++;
		}
	}
}

int main() {
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<4; i++){
		scanf("%d", &oper[i]);
	}
	
	DFS(1, a[0]);
	
	printf("%d\n", max);
	printf("%d\n", min);

	return 0;
}
