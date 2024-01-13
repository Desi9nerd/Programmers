#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
vector<vector<int>> dp;

int Cal(int start, int end)
{
	if(start == end){
		return 0;
	}

	if(dp[start][end] != 2147000000){
		return dp[start][end];
	}

	// start부터 end까지의 최소 곱셈 연산 횟수를 계산
	for (int k = start; k < end; k++) 
	{
		int count = Cal(start, k) + v[start].first * v[k].second * v[end].second + Cal(k + 1, end);

		dp[start][end] = min(dp[start][end], count);
	}

	return dp[start][end];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n);
	dp.resize(n, vector<int>(n, 2147000000));
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
	}

	cout << Cal(0, n - 1) << "\n";

	return 0;
}