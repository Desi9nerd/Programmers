#include <iostream>
#include <vector>
#include <set>
using namespace std;

int T;
int n;
vector<int> v;
vector<bool> visited;
vector<int> done;
int cnt;

void DFS(int start)
{
	visited[start] = true; // 방문 처리
	int next = v[start];

	if (visited[next] == false) {
		DFS(next);
	}
	else {
		if (done[next] == 0) {
			for (int i = next; i != start; i = v[i]) {
				cnt++;
			}
			cnt++;
		}
	}

	done[start] = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> n;
		v.resize(n + 1, 0);
		visited.resize(n + 1, false);
		done.resize(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if(visited[i] == false) {
				DFS(i);
			}
		}
		
		cout << n - cnt << "\n";

		v.clear();
		visited.clear();
		done.clear();
	}


	return 0;
}