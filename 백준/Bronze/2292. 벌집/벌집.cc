#include<stdio.h>
using namespace std;	

int main()
{
	int n, sum=1, cnt=1;
	scanf("%d", &n);
	
	while(sum<n)
	{
		sum += (6 * cnt);
		cnt++;
	}
	
	printf("%d", cnt);
		
	return 0;
}