#include <iostream>
#include <vector>
using namespace std;

int n, m;//n 일수, m 챕터의 수
vector<int> day, chapter;
vector<vector<int>> dp;

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	day.resize(m+1);
	chapter.resize(m+1);
	for (int i = 1; i <= m; i++)
		cin >> day[i] >> chapter[i];

	//i개 이하의 챕터를 읽고, j일 이하를 지났을 때 읽을 수 있는 최대 페이지 수
	dp.resize(m+1, vector<int>(n+1, 0));
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++)
		{
			if (j >= day[i])
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-day[i]] + chapter[i]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	
	cout << dp[m][n];

	return 0;
}