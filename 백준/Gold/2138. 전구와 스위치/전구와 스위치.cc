#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
string initial, target;

void toggleSwitch(string& v, int k) {
    for (int i = k - 1; i <= k + 1; i++) {
        if (i >= 0 && i < n) {
            v[i] = v[i] == '0' ? '1' : '0';
        }
    }
}

int solve(string v, bool pressFirst) 
{
    int cnt = 0;
    if (pressFirst) {
        toggleSwitch(v, 0);
        cnt++;
    }
    for (int i = 1; i < n; i++) {
        if (v[i - 1] != target[i - 1]) {
            toggleSwitch(v, i);
            cnt++;
        }
    }
    
    if (v != target) return -1;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> initial >> target;

    int cnt1 = solve(initial, true); // 첫 번째 스위치를 누른 경우
    int cnt2 = solve(initial, false); // 첫 번째 스위치를 누르지 않은 경우

    if (cnt1 == -1 && cnt2 == -1) cout << -1;
    else if (cnt1 == -1) cout << cnt2;
    else if (cnt2 == -1) cout << cnt1;
    else cout << min(cnt1, cnt2);

    return 0;
}