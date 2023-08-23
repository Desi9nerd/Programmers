#include <iostream>
#include <vector>
using namespace std;

int t, n, m; //t 테스트 케이스 수, n 동전의 가지 수

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	
	while (t--)
	{
		cin >> n;
		vector<int> coins(n+1);
		for (int i = 1; i <= n; i++)
		{
			cin >> coins[i];
		}

		cin >> m;

		/* 방법 1: 이중배열 dp
		//dp[][]는 i개의 동전 종류를 사용했을때 j원(금액)을 만들 수 있는 경우의 수 //i의 동전 종류는 동전 종류 입력순
		vector<vector<int>> dp(n+1, vector<int>(m+1));
		dp[0][0] = 1; //0원을 만드는 방법은 아무 동전도 사용하지 않는 경우 1가지 방법이 있다.

		for (int i = 1; i <= n; i++) 
		{
			for (int j = 0; j <= m; j++) //주의! j는 0부터 시작!
			{
				dp[i][j] = dp[i - 1][j]; //이전 동전까지 사용한 경우의 수 복사

				if (j >= coins[i])
					dp[i][j] += dp[i][j - coins[i]]; //i번째 동전을 사용하여 j원을 만들 수 있는 경우의 수를 더한다.
			}
		}

		cout << dp[n][m] << "\n";
		*/

		//방법 2
		vector<int> dp(m + 1, 0);
		dp[0] = 1; //0원을 만드는 방법은 아무 동전도 사용하지 않는 경우 1가지 방법이 있다.

		for (int i = 1; i <= n; i++) {
			for (int j = coins[i]; j <= m; j++) 
			{
				dp[j] += dp[j - coins[i]];
			}
		}

		cout << dp[m] << "\n";


		//디버깅용
		//cout << "\n";
		//for (int i = 1; i <= n; i++) {
		//	for (int j = 1; j <= m; j++)
		//	{
		//		cout << dp[i][j] << " ";
		//	}
		//	cout <<"\n";
		//}
		//
	}


	return 0;
}