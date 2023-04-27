#include <stdio.h>

int main()
{
    int t, a, b, value;
    scanf("%d", &t);
    
    for(int i=0; i<t; i++){
        value=1;
        scanf("%d %d", &a, &b);
        
        for(int j=0; j<a; j++)
        {
        	value *= b-j;
        	value /= 1+j;
		}
		
		printf("%d\n", value);
    }
        
    return 0;
}