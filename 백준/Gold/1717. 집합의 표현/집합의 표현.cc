#include<stdio.h>
using namespace std;

int n, m;
int unf[1000001];

int Find(int k)
{
	if(k==unf[k]) return k;
	else return unf[k]=Find(unf[k]);
}

void Union(int a, int b)
{
	a=Find(a);
	b=Find(b);
	
	if(a!=b) unf[a]=b;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		unf[i]=i;
	}
	
	for(int i=1; i<=m; i++){
		int x, a, b;
		scanf("%d %d %d", &x, &a, &b);
        
		if(x==0){
			Union(a, b);
		}
		else if(x==1){
			if(Find(a)==Find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}