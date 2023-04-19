#include<stdio.h>
using namespace std;	

int rect[100][100];

int main()
{
	int n, x, y, cnt=0;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		
		for(int j=0; j<10; j++){
			for(int k=0; k<10; k++){
				if(rect[x+j][y+k]==0){
					rect[x+j][y+k]=1;
					cnt++;	
				}	
			}
		}
	}
	
	printf("%d", cnt);
		
	return 0;
}