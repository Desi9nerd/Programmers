#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> 
using namespace std;

int n;
vector<int> graph[1000001];
int dp[1000001][2];

int DFS(int curr, int prev, int state) // curr: 현재 노드, prev: 이전 노드, state: 선택 여부
{
	if (dp[curr][state] != -1) return dp[curr][state];

	int answer = 0;

	if (state == 0)
	{
		for (int i = 0; i < graph[curr].size(); i++)
		{
			int next = graph[curr][i];

			if (next == prev) continue;

			answer += DFS(next, curr, 1);
		}

		return dp[curr][state] = answer;
	}
	else // state == 1 인 경우
	{
		for (int i = 0; i < graph[curr].size(); i++)
		{
			int next = graph[curr][i];

			if (next == prev) continue;

			answer += min(DFS(next, curr, 0), DFS(next, curr, 1));
		}

		return dp[curr][state] = answer + 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n-1; i++) { 
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << min(DFS(1, 0, 0), DFS(1, 0, 1));

	return 0;
}
