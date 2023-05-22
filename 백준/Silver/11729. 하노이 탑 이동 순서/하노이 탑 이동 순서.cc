#include<stdio.h>
#include <vector>
using namespace std;

int n, i=0, j=0, cnt=0;
vector<pair<int, int>> v;

void Hannoi(int n, int from, int mid, int to)
{
	if (n == 0) return;

	Hannoi(n-1, from, to, mid);
	v.push_back(pair<int, int>(from, to));
	Hannoi(n-1, mid, from, to);
	cnt++;
}

int main()
{	
	scanf("%d", &n);
	
	Hannoi(n, 1, 2, 3);

	printf("%d\n", cnt);

	for(int i=0; i<v.size(); i++)
	{
		printf("%d %d\n", v[i].first, v[i].second);
	}

	return 0;
}