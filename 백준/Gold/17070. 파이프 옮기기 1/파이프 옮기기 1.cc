#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> v;
int dp[16][16][3]; // 0: 가로, 1: 세로, 2: 대각선

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n, vector<int>(n));
	for (int y = 0; y < n; y++){
		for (int x = 0; x < n; x++) {
			cin >> v[y][x];
		}
	}

	dp[0][1][0] = 1;
	for (int i = 2; i < n; i++) {
		if (v[0][i] == 1){
			dp[0][i][0] = 0;
		}
		else{
			dp[0][i][0] = dp[0][i-1][0];
		}
	}

	for (int y = 1; y < n; y++) {
		for (int x = 1; x < n; x++) 
		{
			if (v[y][x] == 1) { // 벽O
				dp[y][x][0] = 0;
				dp[y][x][1] = 0;
				dp[y][x][2] = 0;
			}
			else { // 벽X
				dp[y][x][0] = dp[y][x - 1][0] + dp[y][x - 1][2];
				dp[y][x][1] = dp[y - 1][x][1] + dp[y - 1][x][2];

				if (v[y-1][x] == 0 && v[y][x-1] == 0)
				{
					dp[y][x][2] = dp[y - 1][x - 1][0] + dp[y - 1][x - 1][1] + dp[y - 1][x - 1][2];
				}
			}
		}
	}

	cout << dp[n-1][n-1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << "\n";

	return 0;
}