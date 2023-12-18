#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[9], ch[9];

void DFS(int idx, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i <= n; i++)
	{
		if (ch[i] == 0)
		{
			ch[i] = 1;
			arr[cnt] = i;
			DFS(i + 1, cnt + 1);
			ch[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	DFS(1, 0);

	return 0;
}
