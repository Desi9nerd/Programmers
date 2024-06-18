#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dirY[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dirX[8] = { 0, -1, 0, 1, -1, 1, 1, -1 };

int n;
vector<string> v;

void Cal(int y, int x)
{
	int cnt = 0;

	for (int i = 0; i < 8; i++) {
		int ny = y + dirY[i];
		int nx = x + dirX[i];

		if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
		if (v[ny][nx] == '.') continue;

		cnt += (v[ny][nx] - '0');
	}

	if (cnt >= 10) {
		cout << "M";
		return;
	}

	cout << cnt;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n);
	
	for (int y = 0; y < n; y++) {
		cin >> v[y];
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) 
		{
			if (v[y][x] == '.') {
				Cal(y, x);
			}
			else {
				cout << "*";
			}
		}
		cout << "\n";
	}

	return 0;
}