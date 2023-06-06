#include<stdio.h>
#include<algorithm>
using namespace std;

int tri[501][501], sum[501][501];

int main() {
	int n, maxValue=0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}

	sum[0][0] = tri[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				sum[i][j] = sum[i-1][j] + tri[i][j];
			}
			else if (j == i) {
				sum[i][j] = sum[i-1][j-1] + tri[i][j];
			}
			else {
				sum[i][j] = max(sum[i-1][j-1], sum[i-1][j]) + tri[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		maxValue = max(maxValue, sum[n - 1][i]);
	}

	printf("%d", maxValue);

	return 0;
}