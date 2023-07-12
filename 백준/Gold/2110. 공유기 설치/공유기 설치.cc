#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> v;

bool isValid(int distance)
{
	int cnt = 1;
	int lastInstalled = v[0];

	for (int i = 1; i < n; i++)
	{
		if (v[i] - lastInstalled >= distance)
		{
			cnt++;
			lastInstalled = v[i];
		}
	}

	return cnt >= c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	cin >> n >> c;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());//집 오름차순 정렬

	//  1        2       4        8        9
	//v[0],    v[1],    v[2],    v[3],    v[4]
	//	    1        2       4        1


	//이분 탐색 초기값 설정.
	int left = 1;
	int right = v[n - 1] - v[0];
	int result = 0;//두 공유기의 최대 거리

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (isValid(mid))
		{
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << result;


	return 0;
}