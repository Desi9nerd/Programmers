#include <iostream>
using namespace std;

int n;
int comb[53][53];
const int mod = 10007;

int Combination(int N, int K) 
{
	if (comb[N][K] != 0) return comb[N][K];
	else if (K == 0 || K == N) {
		comb[N][K] = 1;
	}
	else {
		comb[N][K] = (Combination(N - 1, K - 1) + Combination(N - 1, K)) % mod;
	}

	return comb[N][K];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	int answer = 0;
	for (int i = 1; i <= n / 4; i++) {
		if (i % 2 == 1) {
			answer += (Combination(13, i) * Combination(52 - i*4, n - i*4)) % mod;
			answer = answer % mod;
		}
		else {
			answer -= (Combination(13, i) * Combination(52 - i*4, n - i*4)) % mod;
			answer = (answer + mod) % mod;
		}
	}

	cout << answer;

	return 0;
}