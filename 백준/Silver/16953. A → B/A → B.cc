#include <iostream>
using namespace std;

int a, b;
int cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b;

	bool success = false;
	while(b > 0)
	{
		if (b == a) {
			success = true;
			break;
		}

		int temp = b;
		if (b % 2 == 0){
			b /= 2;
		}
		else if (b % 10 == 1){
			b /= 10;
		}

		if (temp == b) break; // 위의 2가지 조건 둘 다 해당하지 않는 경우

		cnt++;
	}

	cnt = success ? cnt+1 : -1;
	cout << cnt;

	return 0;
}