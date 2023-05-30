#include<stdio.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	int num[n+1];
	int sum[n+1];
	sum[0]=0;
	
	for(int i=1; i<=n; i++){
		scanf("%d", &num[i]);
		sum[i]=sum[i-1]+num[i];
	}
	
	for(int i=1; i<=m; i++){
		int a, b, result=0;
		scanf("%d %d", &a, &b);
		
		result=sum[b]-sum[a-1];
		
		printf("%d\n", result);
	}
	
	return 0;
}