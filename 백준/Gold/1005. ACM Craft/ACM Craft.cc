#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T; // 테스트케이스의 개수
int n, k; // n: 건물의 개수, k: 건물간의 건설순서 규칙의 총 개수
int w; // 승리하기 위해 건설해야 할 건물의 번호

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T; 
    while (T--) { 
        cin >> n >> k; 
        vector<int> time(n + 1);        // 각 건물을 짓는데 걸리는 시간을 저장하는 벡터
        vector<int> inDegree(n + 1, 0); // 각 건물에 대한 진입차수를 저장하는 벡터
        vector<int> result(n + 1, 0);   // 각 건물을 짓는데 필요한 최소 시간을 저장하는 벡터
        vector<vector<int>> graph(n + 1); // 각 건물의 건설 순서를 나타내는 그래프
        queue<int> Q;                   // 진입차수가 0인 건물을 저장하는 큐

        for (int i = 1; i <= n; i++) {
            cin >> time[i]; // 각 건물을 짓는데 걸리는 시간 입력
        }

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b; // 건물의 건설 순서 입력
            graph[a].push_back(b); // a 건물 다음에 b 건물을 지을 수 있음을 표시
            inDegree[b]++; // b 건물의 진입차수 증가
        }

        cin >> w; // 승리하기 위해 건설해야 할 건물의 번호 입력

        // 위상 정렬 알고리즘 시작
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) { // 진입차수가 0인 건물을 큐에 추가
                Q.push(i);
                result[i] = time[i]; // 해당 건물을 짓는데 필요한 시간 저장
            }
        }

        while (!Q.empty()) { // 큐가 빌 때까지
            int cur = Q.front(); // 현재 건물
            Q.pop();
            for (int next : graph[cur]) // 현재 건물 이후에 지을 수 있는 건물들에 대하여
            { 
                result[next] = max(result[next], result[cur] + time[next]); // 현재 건물을 짓는데 필요한 시간과 다음 건물을 짓는데 필요한 시간 중 큰 값 선택
                inDegree[next]--; // 다음 건물의 진입차수 감소
                
                if (inDegree[next] == 0) { // 다음 건물의 진입차수가 0이 되면
                    Q.push(next); // 큐에 추가
                }
            }
        }

        cout << result[w] << "\n"; // 승리하기 위해 건설해야 할 건물을 짓는데 필요한 최소 시간 출력
    }

    return 0;
}
