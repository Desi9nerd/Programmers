#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int n, m, i, j, k, sum, max=0;
    scanf("%d %d", &n, &m);
    vector<int> v;

	for(int i=0; i<n; i++){
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    for(i=0; i<n-2; i++){
        
	    for(j=i+1; j<n-1; j++){
		    for(k=j+1; k<n; k++)
		    {
                sum = 0;
                sum = v[i] + v[j] + v[k];
		        if(sum<=m)
		        {
		            if (sum > max) max = sum;
		        } 
		    }
	    }
    }

    printf("%d\n", max);

    return 0;
}