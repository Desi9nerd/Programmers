#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

long long container[31][31];

long long DFS(int m, int r)
{
    if (container[m][r] > 0) return container[m][r];

    if (m == r || m == 1) return 1;
	if (r == 1) return m;

	return container[m][r] = DFS(m - 1, r) + DFS(m - 1, r - 1);
}

int main() {
    int t;
    scanf("%d", &t);

    int a, b;
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);

        printf("%lld\n", DFS(b, a));
    }

    return 0;
}
