#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int w, n;
    cin >> w >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<bool> dp(400001, false);

    for (int i = 0; i < n - 2; i++) 
    {
        for (int j = 0; j < i; j++) {
            dp[v[i] + v[j]] = true;
        }
        
        for (int j = i + 2; j < n; j++) {
            int t = w - v[i + 1] - v[j];
            
            if (t < 0) break;
            if (t <= 400000 && dp[t]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}