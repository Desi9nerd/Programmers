#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

int n, m, k; // n: 도시의 수, m: 도로의 수, k: 세금 인상 횟수
int s, d;
vector<vector<pair<int, int>>> road;
vector<vector<int>> dist;

struct Path {
    int city, cost, cnt;

    Path(int a, int b, int c) {
        city = a;
        cost = b;
        cnt = c;
    }

    // 우선순위 큐에서 비용이 낮은 것을 높은 우선순위로 처리하기 위해 비교 연산자 수정
    bool operator>(const Path& oper) const {
        return cost > oper.cost;
    }
};

void Calc()
{
    priority_queue<Path, vector<Path>, greater<Path>> pQ; // 비용이 낮은 것이 높은 우선순위로 오도록 수정
    pQ.push({ s, 0, 0 }); // 시작도시 s, 비용 0 을 시작값으로 설정
    dist[s][0] = 0;

    while (!pQ.empty())
    {
        int nowCity = pQ.top().city;
        int nowCost = pQ.top().cost;
        int nowCnt = pQ.top().cnt;
        pQ.pop();

        if (dist[nowCity][nowCnt] < nowCost) continue;

        for (int i = 0; i < road[nowCity].size(); i++)
        {
            int nextCity = road[nowCity][i].first;
            int nextCost = nowCost + road[nowCity][i].second;
            int nextCnt = nowCnt + 1;

            if (nextCnt < n && dist[nextCity][nextCnt] > nextCost) { // 추가된 경로의 개수가 n 미만일 때만 갱신
                dist[nextCity][nextCnt] = nextCost;
                pQ.push({ nextCity, nextCost, nextCnt });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    cin >> s >> d;
    road.resize(n + 1);
    dist.resize(n + 1, vector<int>(n + 1, INF));

    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w; // 양방향 도로
        road[a].push_back({ b, w });
        road[b].push_back({ a, w });
    }

    Calc();

    int answer = INF;
    for (int i = 0; i <= n; i++) { // 모든 가능한 경로를 확인        
        answer = min(answer, dist[d][i]);
    }
    cout << answer << "\n";

    int tax = 0;
    for (int i = 0; i < k; i++)
    {
        int input;
        cin >> input; // 세금 인상 입력 받기
        tax += input;

        int answer = INF;
        for (int j = 0; j < n; j++) // 세금 인상 후 비용 계산
        {
            answer = min(answer, dist[d][j] + j * tax);
		}

		cout << answer << "\n";
	}

	return 0;
}