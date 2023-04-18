#include<stdio.h>
using namespace std;	

char s[5][15];

int main()
{
	for(int i=0; i<5; i++){
		scanf("%s", s[i]);
	}
	
	for(int x=0; x<15; x++)
	{
		for(int y=0; y<5; y++)
		{
	   		if (s[y][x] == NULL) continue;
			printf("%c", s[y][x]);
		}
	}

	return 0;
}