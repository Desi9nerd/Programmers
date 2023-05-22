#include<stdio.h>
#include <vector>
using namespace std;

int n, i=0, j=0, cnt=0;
vector<int> v1, v2;

void Hannoi(int n, int from, int mid, int to)
{
	if (n == 0) return;

	Hannoi(n-1, from, to, mid);
	v1.push_back(from);
	v2.push_back(to);
	Hannoi(n-1, mid, from, to);
	cnt++;
}

int main()
{	
	scanf("%d", &n);
	
	Hannoi(n, 1, 2, 3);

	printf("%d\n", cnt);

	for(int i=0; i<v1.size(); i++)
	{
		printf("%d %d\n", v1[i], v2[i]);
	}

	return 0;
}