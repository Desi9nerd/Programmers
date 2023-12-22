#include <iostream>
#include <vector>
using namespace std;

int n; // 체스판의 크기 n x n
vector<vector<int>> v; // 체스판
vector<int> l, r; // 흰색과 검은색 2가지 대각선 방향
int answer[2]; // 흰색칸, 검은색칸에 놓일 수 있는 비숍의 최대 개수

void BackT(int y, int x, int cnt, int color)
{
	if (x >= n) {
		y++;
		if (x % 2 == 0) x = 1;
		else x = 0;
	}

	if (y >= n) {
		answer[color] = max(answer[color], cnt);
		return;
	}

	if (v[y][x] && l[x - y + n-1] == 0 && r[y + x] == 0)
	{
		l[x - y + n-1] = 1;
		r[y + x] = 1;
		BackT(y, x + 2, cnt + 1, color);
		l[x - y + n-1] = 0;
		r[y + x] = 0;
	}
	BackT(y, x + 2, cnt, color);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n, vector<int>(n));
	l.resize(n * 2);
	r.resize(n * 2);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> v[y][x];
		}
	}

	BackT(0, 0, 0, 0);
	BackT(0, 1, 0, 1);

	cout << answer[0] + answer[1] << "\n";

	return 0;
}