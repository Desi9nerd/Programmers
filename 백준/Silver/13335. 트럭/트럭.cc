#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, w, l;
    cin >> n >> w >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    queue<pair<int, int>> Q; // (트럭 무게, 다리 위에서의 시간)
    int time = 0, totalWeight = 0, i = 0;

    while (i < n || !Q.empty()) {
        // 시간이 지나면 다리 위의 트럭을 제거
        if (!Q.empty() && Q.front().second == time) {
            totalWeight -= Q.front().first;
            Q.pop();
        }

        // 새로운 트럭이 다리에 올라갈 수 있는지 확인
        if (i < n && totalWeight + v[i] <= l && Q.size() < w) {
            totalWeight += v[i];
            Q.push({v[i], time + w}); // 트럭 무게와 다리를 건널 시간을 저장
            i++;
        }

        time++;
    }

    cout << time << "\n";

    return 0;
}
