#include <queue>
#include <vector>
using namespace std;

int solution(int x, int y, int n) {
    vector<int> visited(1000001, -1); // 방문 체크 및 연산 횟수를 저장할 배열
    queue<int> q;

    visited[y] = 0; // 시작점의 연산 횟수는 0
    q.push(y);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == x) // x에 도달한 경우
            return visited[cur];

        // 가능한 모든 연산을 수행
        if (cur - n >= 0 && visited[cur - n] == -1) {
            q.push(cur - n);
            visited[cur - n] = visited[cur] + 1;
        }
        if (cur % 2 == 0 && visited[cur / 2] == -1) {
            q.push(cur / 2);
            visited[cur / 2] = visited[cur] + 1;
        }
        if (cur % 3 == 0 && visited[cur / 3] == -1) {
            q.push(cur / 3);
            visited[cur / 3] = visited[cur] + 1;
        }
    }

    return -1; // x에 도달할 수 없는 경우
}
