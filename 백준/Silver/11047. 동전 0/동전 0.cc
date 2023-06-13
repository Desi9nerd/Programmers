#include<iostream>
using namespace std;

int n, k, cnt=0;
int coin[11];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	for (int i = n; i > 0; i--)
	{
		if (k == 0) break;

		cnt += k / coin[i];

		k %= coin[i];
	}

	cout << cnt;

	return 0;
}