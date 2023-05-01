#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n, x1, y1, r1, x2, y2, r2;
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		double temp = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
		double dif = abs(r1 - r2);

		if (x1 == x2 && y1 == y2 && r1==r2) printf("-1\n");
		else if (r1 + r2 > temp && (dif<temp)) printf("2\n");
		else if (r1 + r2 == temp || dif == temp) printf("1\n");
		else printf("0\n");
	}
	
	return 0;
}
