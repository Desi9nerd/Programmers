#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, k;
	cin >> N >> k;

	int low = 1, high = k;
	while (low < high) {
		int mid = (low + high) / 2, cnt = 0;

		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / i);
		}
		if (cnt < k) low = mid + 1;
		else high = mid;
	}

	cout << high << '\n';
}