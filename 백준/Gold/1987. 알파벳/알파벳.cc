#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

int r, c;
vector<vector<char>> v;
bool alpha[26];
int answer;

void BackT(int y, int x, int cnt)
{
	answer = max(answer, cnt);

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dirY[i];
		int nx = x + dirX[i];

		if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
		if (alpha[v[ny][nx] - 'A'] == true) continue;

		alpha[v[ny][nx] - 'A'] = true;
		BackT(ny, nx, cnt + 1);
		alpha[v[ny][nx] - 'A'] = false;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;
	v.resize(r, vector<char>(c));
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cin >> v[y][x];
			if (y == 0 && x == 0) {
				alpha[v[0][0] - 'A'] = true;
			}
		}
	}

	BackT(0, 0, 1);

	cout << answer;

	return 0;
}