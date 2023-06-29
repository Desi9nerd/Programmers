#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, abilitySum = 0, result = 2147000000;
int S[21][21];
bool ch[21];

void DFS(int x, int cnt) {
    if (cnt == n / 2) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ch[i] && ch[j]) sum1 += S[i][j];
                if (!ch[i] && !ch[j]) sum2 += S[i][j];
            }
        }
        result = min(result, abs(sum1 - sum2));
        return;
    }

    for (int i = x; i < n; i++) {
        if (!ch[i]) {
            ch[i] = true;
            DFS(i + 1, cnt + 1);
            ch[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> S[i][j];
        }
    }
    DFS(0, 0);
    cout << result;

    return 0;
}
