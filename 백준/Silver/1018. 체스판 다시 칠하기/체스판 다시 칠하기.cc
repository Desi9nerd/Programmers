#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char board[50][50];

    // 보드 입력 받기
    for (int i = 0; i < n; i++) {
        scanf("%s", board[i]);
    }

    int minCnt = 2500; // 최대 칠해야 하는 칸의 개수로 초기화

    // 모든 경우의 수 탐색
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int cnt = 0;

            // 시작이 W인 경우와 B인 경우로 나누어 계산
            // 체스판의 왼쪽 위 모서리가 W인 경우
            for (int x = i; x < i + 8; x++) {
                for (int y = j; y < j + 8; y++) {
                    if ((x + y) % 2 == 0) {
                        // W로 시작해야 하는데 B인 경우
                        if (board[x][y] == 'B') {
                            cnt++;
                        }
                    } else {
                        // B로 시작해야 하는데 W인 경우
                        if (board[x][y] == 'W') {
                            cnt++;
                        }
                    }
                }
            }
            minCnt = (cnt < minCnt) ? cnt : minCnt; // 최솟값 갱신

            // 체스판의 왼쪽 위 모서리가 B인 경우
            cnt = 0;
            for (int x = i; x < i + 8; x++) {
                for (int y = j; y < j + 8; y++) {
                    if ((x + y) % 2 == 0) {
                        // B로 시작해야 하는데 W인 경우
                        if (board[x][y] == 'W') {
                            cnt++;
                        }
                    } else {
                        // W로 시작해야 하는데 B인 경우
                        if (board[x][y] == 'B') {
                            cnt++;
                        }
                    }
                }
            }
            minCnt = (cnt < minCnt) ? cnt : minCnt; // 최솟값 갱신
        }
    }

    printf("%d\n", minCnt);

    return 0;
}