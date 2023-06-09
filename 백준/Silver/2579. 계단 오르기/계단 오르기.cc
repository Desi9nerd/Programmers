#include <iostream>
#include <algorithm>
using namespace std;

int n;
int stair[301];
int sum[301];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> stair[i];
	}

	sum[1] = stair[1];
	sum[2] = stair[1] + stair[2];
	sum[3] = max(stair[1], stair[2]) + stair[3];
	sum[4] = max(stair[1] + max(stair[2], stair[3]), stair[2]) + stair[4];

	for(int i=5; i<=n; i++)
	{
		sum[i] = max(sum[i-3] + stair[i-1], sum[i-2]) + stair[i];
	}

	cout << sum[n];

	return 0;
}