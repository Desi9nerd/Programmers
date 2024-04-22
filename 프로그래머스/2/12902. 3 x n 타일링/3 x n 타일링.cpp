#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

vector<long long> dp;

int solution(int n) {
    if (n % 2 == 1) return 0;

    dp.resize(n + 1);
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;

    long long sum = 1;

    for (int i = 6; i <= n; i += 2)
    {
        sum += dp[i - 4];
        sum %= MOD;

        dp[i] = (dp[i - 2] * 3 + sum * 2) % MOD;

    }
    
    return dp[n];
}