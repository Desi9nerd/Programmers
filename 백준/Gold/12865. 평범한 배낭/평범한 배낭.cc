#include <iostream>
#include <vector>
using namespace std;

int n, k;//n은 물품의 수, k는 배낭의 최대 수용 무게
vector<int> w, v;//w는 각 물건의 무게, v는 물건의 가치
vector<vector<int>> dp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	w.resize(n + 1);
	v.resize(n + 1);

	for(int i = 1; i <= n; i++){
		//물건의 무게(w)와 가치(v)를 각각 다른 배열에 담는다.
		cin >> w[i] >> v[i];
	}

	//dp[i][j]의 값 = i개의 물건과 현재 배낭의 무게 j를 고려할 때 배낭에 담긴 물건들의 최대 가치
	//dp[i][j]배열에 i이하 개수의 물건, j이하의 무게로 가질 수 있는 물건의 최대 가치를 담는다.
	dp.resize(n + 1, vector<int>(k + 1));

	for(int i = 1; i <= n; i++)//i는 물건의 개수
	{
		for (int j = 1; j <= k; j++)//j는 배낭의 무게
		{
			if (j >= w[i])//현재 탐색 중인 물건 i의 무게(w[i])가 j보다 작거나 같을 경우(즉, 현재 배낭 무게 j에 다른 물건들과 함께 물건 i를 담을 수 있을 경우)
				dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
			else//현재 물건 i의 무게가 j보다 클 경우(즉, 현재 배낭 무게 j에 물건 i를 담을 수 없을 경우)
				dp[i][j] = dp[i - 1][j];
		}
	}


	cout << dp[n][k];   

	return 0;
}