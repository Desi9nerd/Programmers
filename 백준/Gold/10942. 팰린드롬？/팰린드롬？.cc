#include <iostream>
#include <vector>
using namespace std;

int n, m; // n: 숫자 배열의 크기, m: 질의의 수
vector<int> v;
vector<vector<bool>> dp; // 팰린드롬 여부를 저장할 2차원 벡터

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n + 1);
	dp.resize(n + 1, vector<bool>(n + 1, false));
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	// 길이가 1인 경우, 모든 숫자는 자기 자신만으로 팰린드롬
	for (int i = 1; i <= n; i++) {
		dp[i][i] = true;
	}

	// 길이가 2인 경우, 연속된 두 숫자가 같으면 팰린드롬
	for (int i = 1; i < n; i++) {
		if (v[i] == v[i + 1]) {
			dp[i][i + 1] = true;
		}
	}

	// 길이가 3 이상인 경우 
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) 
		{
			if (v[i] == v[j] && dp[i + 1][j - 1] == true) {
				dp[i][j] = true;
			}
		}
	}

	cin >> m;
	int s, e;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}

	return 0;
}