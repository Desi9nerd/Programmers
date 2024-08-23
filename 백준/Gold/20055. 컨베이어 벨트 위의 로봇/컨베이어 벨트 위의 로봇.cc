#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, k;
int answer; // 몇 번째 단계인가
deque<pair<int, bool>> dQ; // 내구도, 로봇 배치 여부

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < 2 * n; i++) {
        int input;
        cin >> input;
        dQ.push_back({ input, false });
    }

    while (true) 
    {
        answer++;

        // 1. 벨트 회전
        dQ.push_front(dQ.back());
        dQ.pop_back();

        // 로봇이 내려가는 위치(n-1)에서 로봇을 내려야 한다.
        if (dQ[n - 1].second) {
            dQ[n - 1].second = false;
        }

        // 2. 로봇 이동
        for (int i = n - 2; i >= 0; i--) 
        {
            if (dQ[i].second && false == dQ[i + 1].second && dQ[i + 1].first > 0) 
            {
                dQ[i].second = false;
                dQ[i + 1].second = true;
                dQ[i + 1].first--;

                if (dQ[i + 1].first == 0) k--;
            }
        }

        // 로봇이 내려가는 위치(n-1)에서 로봇을 내려야 한다.
        if (dQ[n - 1].second) {
            dQ[n - 1].second = false;
        }

        // 3. 첫 번째 위치에 로봇 올리기
        if (dQ[0].first > 0) {
            dQ[0].second = true;
            dQ[0].first--;
            if (dQ[0].first == 0) k--;
        }

        // 4. 내구도가 0인 칸이 k개 이상이면 종료
        if (k <= 0) break;
    }

    cout << answer;

    return 0;
}
