#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dirY[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dirX[8] = { 0, -1, 0, 1, -1, 1, 1, -1 };

int n;
vector<string> v;
vector<vector<char>> result;

void Cal(int y, int x)
{
	int cnt = 0;

	for (int i = 0; i < 8; i++) {
		int ny = y + dirY[i];
		int nx = x + dirX[i];

		if (ny < 0 || n <= ny || nx < 0 || n <= nx) continue;
		if (v[ny][nx] == '*') cnt++;
	}

	result[y][x] = cnt + '0';
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n);
	result.resize(n, vector<char>(n));

	for (int y = 0; y < n; y++) {
		cin >> v[y];
	}

	bool fail = false;
	string input;
	for (int y = 0; y < n; y++) 
	{
		cin >> input;
		for (int x = 0; x < n; x++)
		{
			if (input[x] == 'x') {
				if (v[y][x] == '*') {
					fail = true;
				}
				Cal(y, x);
			}
			else {
				result[y][x] = '.';
			}
		}
	}

	if (fail)
	{
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++){
				if (v[y][x] == '*')
					cout << '*';
				else
					cout << result[y][x];
			}
			cout << "\n";
		}
	}
	else
	{
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				cout << result[y][x];
			}
			cout << "\n";
		}
	}

	return 0;
}