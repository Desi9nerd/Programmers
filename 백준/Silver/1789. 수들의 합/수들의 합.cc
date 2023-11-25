#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long S;
	cin >> S;

	long long sum = 0, num = 1;
	int cnt = 0;

	while (1) {
		sum = sum + num;
		cnt++;
		if (sum > S) {
			cnt--;
			break;
		}
		num++;
	}

	cout << cnt;
	return 0;
}