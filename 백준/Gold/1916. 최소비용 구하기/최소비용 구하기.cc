#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, result;
int ch[1001];

struct Edge {
    int e;
    int cost;
    Edge(int a, int b) {
        e = a;
        cost = b;
    }
    bool operator<(const Edge& b)const {
        return cost > b.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<Edge> Q;
    vector<pair<int, int>> graph[1001];

    cin >> n >> m;

    vector<int> dist(n + 1, 2147000000);//최대값을 기본값으로 세팅.

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    int start, end;
    cin >> start >> end;

    Q.push(Edge(start, 0));
    dist[start] = 0;

    while (!Q.empty())
    {
        int now = Q.top().e;
        int cost = Q.top().cost;

        Q.pop();

        if (cost > dist[now]) continue;

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            int nextCost = cost + graph[now][i].second;

            if (dist[next] > nextCost)
            {
                dist[next] = nextCost;
                Q.push(Edge(next, nextCost));
            }
        }
    }

    cout << dist[end];

    return 0;
}