#include <iostream>
using namespace std;
long long factorial[4000001];
long long MOD = 1000000007;

long long CustomPow(long long num, long long x)
{
	if (x == 0) return 1;
	else if (x == 1) return num;
	else if (x % 2 == 0) {
		long long temp = CustomPow(num, x / 2);
		return (temp * temp) % MOD;
	}
	else {// remain % 2 == 1
		long long temp = CustomPow(num, x - 1);
		return (temp * num) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int m, n, k;
	cin >> m;

	// factorial 미리 구해놓기
	factorial[0] = 1;
	for (int i = 1; i < 4000001; i++) {
		factorial[i] = factorial[i - 1] * i;
		factorial[i] %= MOD;
	}

	for (int i = 0; i < m; i++) {
		cin >> n >> k;
		long long up = factorial[n];
		long long down = (factorial[k] * factorial[n - k]) % MOD;

		down = CustomPow(down, MOD - 2) % MOD; // 페르마의 소정리

		cout << (up * down) % MOD << '\n';
	}

	return 0;
}