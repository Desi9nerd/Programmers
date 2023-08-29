#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v, LIS;

// key값 이상의 크기의 수 중에서 가장 먼저 나온 수의 인덱스를 반환
int BinarySearch(vector<int>& v, int key)
{
	int left = 0;
	int right = v.size() - 1;
	int mid;

	while (left < right) 
	{
		int mid = (left + right) / 2;
		
		if (key > v[mid]) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	return right;
}

void Solve() 
{
	int cnt = 1;
	LIS.push_back(v[0]);

	for (int i = 1; i < n; i++) 
	{
		if (LIS.back() < v[i]) {
			LIS.push_back(v[i]);
			cnt++;
		}
		else {
			int idx = BinarySearch(LIS, v[i]);
			LIS[idx] = v[i];
		}
	}

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	v.resize(n); // 주어진 값을 넣는 배열
	LIS.resize(n); // 각 숫자의 최대부분 증가 길이를 기록하는 배열
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	Solve();

	return 0;
}