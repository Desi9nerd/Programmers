#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<char>> v;
char blank = ' ';
char star = '*';

void Tree(int y, int x)
{
	// 첫번째 줄 (꼭직점에 * 1개)
	v[y][x] = star; 
	// 두번째 줄 (* 2개)
	v[y + 1][x - 1] = v[y + 1][x + 1] = star;
	// 세번째 줄 (* 5개)
	v[y + 2][x - 2] = v[y + 2][x - 1] = v[y + 2][x] = v[y + 2][x + 1] = v[y + 2][x + 2] = star; 

	return;
}

void Cal(int y, int x, int n)
{
	if (n == 3) {
		Tree(y, x);
		return;
	}
	
	Cal(y, x, n / 2);
	Cal(y + n / 2, x - n / 2, n / 2);
	Cal(y + n / 2, x + n / 2, n / 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n, vector<char>(n*2 - 1, ' '));
	
	Cal(0, n - 1, n);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n*2 - 1; x++) {
			cout << v[y][x];
		}
		cout << "\n";
	}

	return 0;
}