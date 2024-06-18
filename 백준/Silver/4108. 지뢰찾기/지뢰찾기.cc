#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dirY[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dirX[8] = { 0, -1, 0, 1, -1, 1, 1, -1 };

int r, c;
vector<string> v;

void Cal(int y, int x, const vector<string>& v)
{
	int cnt = 0;

	for (int i = 0; i < 8; i++) {
		int ny = y + dirY[i];
		int nx = x + dirX[i];

		if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
		if (v[ny][nx] == '*') cnt++;
	}

	cout << cnt;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (true)
	{
		cin >> r >> c;
		if (r == 0 && c == 0) break;

		vector<string> v(r);

		for (int y = 0; y < r; y++) {
			cin >> v[y];
		}

		for (int y = 0; y < r; y++) {
			for (int x = 0; x < c; x++)
			{
				if (v[y][x] == '*') {
					cout << "*";
				}
				else {
					Cal(y, x, v);
				}
			}
			cout << "\n";
		}
	}

	return 0;
}