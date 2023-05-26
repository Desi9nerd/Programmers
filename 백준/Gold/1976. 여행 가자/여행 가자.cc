#include<stdio.h>
using namespace std;

int n, m; 
int city[201];

int Find(int k)
{
	if(city[k]==k) return k;
	
	return city[k]=Find(city[k]);
}

void Union(int a, int b)
{
	a=Find(a);
	b=Find(b);
	
	if(a != b) city[a]=b;
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	
	for(int i=1; i<=n; i++){
		city[i]=i;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int input;
			scanf("%d", &input);
			
			if(input==1) {	Union(i, j); }//도시 이어주기 
		}		
	}
	
	int prev;
	scanf("%d", &prev);
		
	for(int i=1; i<m; i++)	
	{
		int curr;
		scanf("%d", &curr);
		
		if(Find(prev)!=Find(curr))
		{
			printf("NO\n");
			return 0;
		}
		
		curr=prev;		
	}
	
	printf("YES\n");
	

	return 0;
}