#include <iostream>
using namespace std;

int n, k;
int answer;

int pwr(int x)
{
	int cnt = 0;
	while(x)
	{
		if (x % 2 != 0) {
			cnt++;
		}

		x /= 2;
	}

	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	if (n <= k){
		cout << "0";
		return 0;
	}
	
	int temp = n;
	while (pwr(temp) > k)
	{
		temp++;
		answer++;
	}

	cout << answer;

	return 0;
}