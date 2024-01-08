#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K; // N: 수빈의 현재 점, K: 동생이 있는 점
int minTime = 2147000000, num;
vector<int> ch(100001, -1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	
	queue<int> Q;
	Q.push(N);
	ch[N] = 1;
	bool firstVisit = true;

	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		if (ch[x] > minTime) continue;

		if (x == K && firstVisit) {
			if (ch[x] < minTime) {
				minTime = ch[x];
				num = 0;
			}
			num++;
		}

		if (x - 1 >= 0 && (ch[x - 1] == -1 || ch[x - 1] == ch[x] + 1)) {
			Q.push(x - 1);
			ch[x - 1] = ch[x] + 1;
		}
		if (x + 1 <= 100000 && (ch[x + 1] == -1 || ch[x + 1] == ch[x] + 1)) {
			Q.push(x + 1);
			ch[x + 1] = ch[x] + 1;
		}
		if (x * 2 <= 100000 && (ch[x * 2] == -1 || ch[x * 2] == ch[x] + 1)) {
			Q.push(x * 2);
			ch[x * 2] = ch[x] + 1;
		}
	}

	cout << minTime-1 << "\n";
	cout << num << "\n";

	return 0;
}