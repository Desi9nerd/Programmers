#include <iostream>
using namespace std;

int n, m, h;
int ch[31][11];

bool Cal() {
    for (int start = 1; start <= n; start++) {
        int x = start;
        for (int y = 1; y <= h; y++) {
            if (ch[y][x]) x++; // 오른쪽으로 이동
            else if (x > 1 && ch[y][x - 1]) x--; // 왼쪽으로 이동
        }
        if (x != start) return false; // 시작점과 도착점이 다르면 false
    }
    return true; // 모든 시작점이 도착점과 같으면 true
}

bool Select(int idx, int NumOfNewLines, int startY, int startX) {
    if (idx == NumOfNewLines) {
        return Cal();
    }

    for (int y = startY; y <= h; y++) {
        for (int x = (y == startY) ? startX : 1; x < n; x++) {
            if (ch[y][x] || (x > 1 && ch[y][x - 1]) || (x < n - 1 && ch[y][x + 1])) {
                continue;
            }

            ch[y][x] = 1;
            if (Select(idx + 1, NumOfNewLines, y, x + 2)) return true;
            ch[y][x] = 0; // 사다리 제거 후 다른 경우 탐색
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int y, x;
        cin >> y >> x;
        ch[y][x] = 1; // 사다리 추가
    }

    if (Cal()) {
        cout << "0";
        return 0;
    }

    for (int i = 1; i <= 3; i++) {
        if (Select(0, i, 1, 1)) {
            cout << i;
            return 0;
        }
    }

    cout << "-1"; // 3개 이하의 사다리로는 조건을 만족할 수 없는 경우
    return 0;
}
