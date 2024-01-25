#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // 메뉴의 총 개수
vector<long long> v;
vector<long long> two;

const int MOD = 1000000007;

//long long modpow(int base, int expo)
//{
//	if (two[expo] != 0) return two[expo];
//
//	if (expo == 0) return 1;
//
//	else if (expo % 2 == 1) {
//		long long result = modpow(base, expo - 1);
//		return two[expo] = (base * result) % 1000000007;
//	}
//	else {
//		long long result = modpow(base, expo / 2);
//		return two[expo] = (result * result) % 1000000007;
//	}
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n);
	two.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	long long temp = 1;
	for (int i = 0; i < n; i++) {
		two[i] = temp - 1;
		temp *= 2;
		temp %= MOD;
	}

	long long maxSco = 0;
	long long minSco = 0;
	for (int i = 0; i < n; i++) {
		minSco += ((two[n-1-i] - 1) * v[i]) % MOD;
		maxSco += ((two[i] - 1) * v[i]) % MOD;
	}

	cout << (maxSco % MOD - minSco % MOD + MOD) % MOD << "\n";

	return 0;
}