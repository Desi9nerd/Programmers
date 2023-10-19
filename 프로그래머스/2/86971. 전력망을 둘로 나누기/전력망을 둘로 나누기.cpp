#include <cmath>
#include <vector>
using namespace std;

// n: 송전탑의 개수, wires: 전선 정보
// answer: 두 전력망이 가지고 있는 송전탑 개수의 차이(절대값)

int cnt;
vector<vector<int>> adj;
vector<int> ch;

void DFS(int curr, int prev = -1)
{
    ch[curr] = 1;

    for (int i = 0; i < adj[curr].size(); i++)
    {
        int next = adj[curr][i];

        if (next != prev) {
            DFS(next, curr);
            ch[curr] += ch[next];
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    adj.resize(n+1);
    ch.resize(n+1);

    for (int i = 0; i < wires.size(); i++)
    {
        int node1 = wires[i][0];
        int node2 = wires[i][1];

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    DFS(1);

    for (int i = 2; i <= n; ++i)
        answer = min(answer, abs(n - 2 * ch[i]));

    return answer;
}
