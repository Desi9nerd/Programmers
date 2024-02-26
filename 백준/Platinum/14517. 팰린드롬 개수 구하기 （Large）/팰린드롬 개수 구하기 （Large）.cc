#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 10007;
string s;
vector<vector<int>> dp; // dp[a][b]

int DFS(int a, int b)
{
    if (a > b) return 0;
    if (a == b) return 1;
    if (dp[a][b] != -1) return dp[a][b];

    dp[a][b] = (DFS(a, b - 1) + DFS(a + 1, b) - DFS(a + 1, b - 1)) % MOD;

    if (dp[a][b] < 0) 
        dp[a][b] += MOD;

    if (s[a] == s[b])
        dp[a][b] = (dp[a][b] + DFS(a + 1, b - 1) + 1) % MOD;

    return dp[a][b] % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> s;
    
    dp.resize(s.size(), vector<int>(s.size(), -1));

    cout << DFS(0, s.size()-1) % MOD;

    return 0;
}
