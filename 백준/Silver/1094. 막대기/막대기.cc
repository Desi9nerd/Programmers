#include <iostream>
using namespace std;

int x; // 입력 받을 수
int cnt; // 막대의 개수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> x;

	// 비트 연산을 이용해 막대기의 개수를 센다
	for(int i = 0; i <= 6; i++) // 64는 2의 6제곱이므로 i는 0부터 6까지
	{
		// 이 연산 결과가 0이 아니면, 해당 비트는 1이므로 막대기가 존재하는 것이고, 그 때마다 cnt를 1씩 증가.
		if (x & (1 << i)) { // x의 i번째 비트가 1이면
			cnt++; // 막대기의 개수를 증가
		}
	}

	cout << cnt;

	return 0;
}