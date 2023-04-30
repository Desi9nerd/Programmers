#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int GCD(int a, int b)
{
	return b ? GCD(b, a % b) : a;
}

int main() {

	int n, max = 0, min = 2147000000, cnt = 0;
	scanf("%d", &n);
	vector<int> t(n);
	vector<int> dist(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
	}
	// 가로수 거리순으로 정렬
	sort(t.begin(), t.end());

	for(int i=0; i< n-1; i++)
	{
		dist[i] = t[i + 1] - t[i];
	}

	int gcd = dist[0];
	for(int i=1; i<n-1; i++)
	{
		gcd = GCD(gcd, dist[i]);
	}

	for (int i = 0; i < n - 1; i++)
	{
		cnt += ((t[i + 1] - t[i]) / gcd) - 1;
	}

	printf("%d\n", cnt);

	return 0;
}
