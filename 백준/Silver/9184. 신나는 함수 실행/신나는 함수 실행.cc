#include<iostream>
using namespace std;

int save[51][51][51];

int w(int a, int b, int c)
{
	if(save[a][b][c]!=0) return save[a][b][c];
	
	if (a <= 0 || b <= 0 || c <= 0) 
	{
		return save[a][b][c] = 1;
	}

	if (a > 20 || b > 20 || c > 20)
    {
    	return save[a][b][c] = w(20, 20, 20);
	}

	if (a < b && b < c) 
    {
    	return save[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	}
	else 
	{
    	return save[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
	}
}

int main() {
	int a, b, c;
		
	while(1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if(a==-1 && b==-1 && c==-1) break;
		
		if (a <= 0 || b <= 0 || c <= 0) printf("w(%d, %d, %d) = 1\n", a, b, c);
		else
		{
			w(a, b, c);	
			printf("w(%d, %d, %d) = %d\n", a, b, c, save[a][b][c]);
		}
	}
	
	return 0;
}