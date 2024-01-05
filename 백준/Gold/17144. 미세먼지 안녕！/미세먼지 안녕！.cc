#include <iostream>
#include <vector>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, -1, 0, 1 };

int r, c, t;
vector<vector<int>> v;
int airLocY, airLocX;

void Spread(int y, int x, vector<vector<int>>& arr)
{
	if (y < 0 || r <= y || x < 0 || c <= x) return;

	int temp = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dirY[i];
		int nx = x + dirX[i];

		if (ny < 0 || r <= ny || nx < 0 || c <= nx) continue;
		if (v[ny][nx] == -1) continue;

		v[ny][nx] += arr[y][x] / 5;
		temp += arr[y][x] / 5;
	}
	v[y][x] -= temp;
}

void AirPurifier(int airy, int airx)
{
	vector<vector<int>> temp(r, vector<int>(c, 0));
	temp = v;

	//공기청정기 윗 부분 (반시계 방향 순환)
	for (int i = 1; i < c; i++)
		temp[airy][i] = v[airy][i - 1];
	for (int i = airy - 1; i >= 0; i--)
		temp[i][c - 1] = v[i + 1][c - 1];
	for (int i = c - 2; i >= 0; i--)
		temp[0][i] = v[0][i + 1];
	for (int i = 1; i < airy; i++)
		temp[i][0] = v[i - 1][0];

	//공기청정기 아랫 부분 (시계 방향 순환)
	for (int i = 1; i < c; i++)
		temp[airy + 1][i] = v[airy + 1][i - 1];
	for (int i = airy + 2; i < r; i++)
		temp[i][c - 1] = v[i - 1][c - 1];
	for (int i = c - 2; i >= 0; i--)
		temp[r - 1][i] = v[r - 1][i + 1];
	for (int i = r - 2; i > airy + 1; i--)
		temp[i][0] = v[i + 1][0];

	temp[airy][1] = 0;
	temp[airy + 1][1] = 0;
	temp[airy][0] = -1;
	temp[airy + 1][0] = -1;

	v = temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> r >> c >> t;
	v.resize(r, vector<int>(c));
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			cin >> v[y][x];

			if (v[y][x] == -1) {
				airLocY = y - 1;
				airLocX = x;
			}
		}
	}

	while (t--)
	{
		vector<vector<int>> tmp(r, vector<int>(c));
		tmp = v;
		for (int y = 0; y < r; y++) {
			for (int x = 0; x < c; x++) {
				if (tmp[y][x] != 0)
				{
					Spread(y, x, tmp);
				}
			}
		}

		//cout << "\n";
		//for (int y = 0; y < r; y++) {
		//	for (int x = 0; x < c; x++) {
		//		cout << v[y][x] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		AirPurifier(airLocY, airLocX);

		//cout << "\n";
		//for (int y = 0; y < r; y++) {
		//	for (int x = 0; x < c; x++) {
		//		cout << v[y][x] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";
	}


	int answer = 0;
	for (int y = 0; y < r; y++) {
		for (int x = 0; x < c; x++) {
			answer += v[y][x];
		}
	}
	cout << answer + 2;

	return 0;
}