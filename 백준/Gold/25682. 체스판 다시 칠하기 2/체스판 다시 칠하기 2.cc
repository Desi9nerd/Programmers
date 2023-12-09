#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m, k;
vector<vector<int>> black, white;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	black.resize(n+1, vector<int>(m+1));
	white.resize(n+1, vector<int>(m+1));

	char input;
	for(int y = 1; y <= n; y++){
		for(int x = 1; x <= m; x++){
			cin >> input;
		
			black[y][x] = black[y - 1][x] + black[y][x - 1] - black[y - 1][x - 1];
			white[y][x] = white[y - 1][x] + white[y][x - 1] - white[y - 1][x - 1];

			if ((y + x) % 2 == 0) {
				if (input == 'B') white[y][x]++;
				else black[y][x]++;
			}
			else {
				if (input == 'W') white[y][x]++;
				else black[y][x]++;
			}
		}
	}

	int cnt = k * k;
	for (int y = k; y <= n; y++) {
		for (int x = k; x <= m; x++) {
			int blackCnt = black[y][x] - black[y - k][x] - black[y][x - k] + black[y - k][x - k];
			int whiteCnt = white[y][x] - white[y - k][x] - white[y][x - k] + white[y - k][x - k];

			cnt = min(cnt, min(blackCnt, whiteCnt));
		}
	}

	cout << cnt << "\n";
	
	return 0;
}