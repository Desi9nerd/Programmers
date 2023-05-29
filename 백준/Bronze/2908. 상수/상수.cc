#include<stdio.h>
using namespace std;	

int main()
{
	int a, b, resultA=0, resultB=0;
	scanf("%d %d", &a, &b);	

	while(a>0)
	{
		int tmpA = a%10;	
		a/=10;
		resultA *= 10;
		resultA += tmpA;
	}
	while(b>0)
	{
		int tmpB = b%10;	
		b/=10;
		resultB *= 10;
		resultB += tmpB;
	}
	
	if(resultA>resultB)	printf("%d", resultA);
	else printf("%d", resultB);

	return 0;
}