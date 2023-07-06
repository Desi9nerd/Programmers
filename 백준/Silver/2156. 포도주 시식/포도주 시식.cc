#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n+2);
    dp.resize(n+2);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    dp[3] = max(max(v[1] + v[3], v[2] + v[3]), v[1] + v[2]);

    for (int i = 4; i <= n; i++) 
    {
        dp[i] = max(max(dp[i - 3] + v[i - 1], dp[i - 2]) + v[i], dp[i-1]);
    }

    cout << dp[n];

    return 0;
}