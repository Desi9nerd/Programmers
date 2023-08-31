#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;//n: 수빈 현재 점, k: 동생 점
queue<pair<int,int>> Q;
vector<int> ch;

int minSec = 2147000000;

void BFS(int n, int k)
{
	Q.push({ n, 0 });
	ch[n] = 1;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int sec = Q.front().second;
		Q.pop();

		if (x == k){
			cout << sec;
			return;
		}

		if (ch[x-1]==0 && 0 <= x-1)
		{
			Q.push({ x - 1, sec + 1 });
			ch[x - 1] = 1;
		}
		if (ch[x+1]==0 && x+1 <= k * 2)
		{
			Q.push({ x + 1, sec + 1 });
			ch[x + 1] = 1;
		}
		if (ch[x*2]==0 && x*2 <= k * 2)
		{
			Q.push({ x * 2, sec + 1 });
			ch[x * 2] = 1;			
		}

	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	ch.resize(1000000);

	BFS(n, k);

	return 0;
}