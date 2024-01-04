#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v(3);
vector<int> dp(3), next_dp(3); // 'next_dp'는 다음 단계의 최적값을 저장하기 위함
vector<int> dpMax(3), next_dpMax(3); 
int minValue = 2147000000, maxValue = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < 3; x++) {
            cin >> v[x];
        }

        if (y == 0) {
            dp = v; // 첫 번째 줄은 입력값으로 초기화
            dpMax = v;
            continue;
        }

        // 다음 단계의 값을 계산하고 저장
        next_dp[0] = v[0] + min(dp[0], dp[1]);
        next_dp[1] = v[1] + min({ dp[0], dp[1], dp[2] });
        next_dp[2] = v[2] + min(dp[1], dp[2]);

        next_dpMax[0] = v[0] + max(dpMax[0], dpMax[1]);
        next_dpMax[1] = v[1] + max({ dpMax[0], dpMax[1], dpMax[2] });
        next_dpMax[2] = v[2] + max(dpMax[1], dpMax[2]);

        dp = next_dp; // 다음 단계의 값을 현재 단계로 업데이트
        dpMax = next_dpMax;
    }

    minValue = *min_element(dp.begin(), dp.end());
    maxValue = *max_element(dpMax.begin(), dpMax.end());

    cout << maxValue << " " << minValue;

    return 0;
}
