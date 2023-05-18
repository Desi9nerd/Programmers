#include <iostream>
using namespace std;

int a[100000];
int dp[100000];

int main() {
	int n, ans;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	ans=a[0];
	
	for(int i=0; i<n; i++)
	{
		dp[i]=a[i];
		
		if(i ==0) continue;
		
		if(dp[i]<dp[i-1]+a[i]){
			dp[i]=dp[i-1]+a[i];
		}
		
		if(dp[i]>ans) ans=dp[i];
	}

	printf("%d", ans);

	return 0;
}