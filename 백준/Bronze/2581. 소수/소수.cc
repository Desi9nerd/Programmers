#include <stdio.h>

using namespace std;

int main()
{
	int m, n, ch=0, flag=0, sum=0, min;
	scanf("%d", &m);
	scanf("%d", &n);
	
	for(int i=m; i<=n; i++)
	{
        if(i==1) continue;
            
		for(int j=2; j<i; j++)
		{
			if(i%j==0) { flag=1; break;}
		}
		
		if(flag==0) 
		{ 
			if(ch==0) { min=i; ch=1;}
			sum+=i; 
		}
		
		flag=0;	
	}
	
	if(sum>0) printf("%d\n%d", sum, min);
	else printf("-1");
	
	return 0;
}