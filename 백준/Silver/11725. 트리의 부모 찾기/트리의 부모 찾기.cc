#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<vector<int>> v(100001);
int ch[100001];
int tree[100001];

void BFS()
{
	queue<int> Q;
	Q.push(1); // 트리의 루트 1 삽입
	ch[1] = 1; // 체크

	while(!Q.empty())
	{
		int parent = Q.front();
		Q.pop();

		for(int i = 0; i < v[parent].size(); i++)
		{
			int child = v[parent][i];

			if(ch[child] == 0)
			{
				tree[child] = parent;
				Q.push(child);
				ch[child] = 1;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int a, b;
	for(int i = 0; i < n-1; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	BFS();

	for(int i = 2; i <= n; i++){
		cout << tree[i] << "\n";
	}

	return 0;
}