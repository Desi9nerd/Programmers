#include <iostream>
#include <vector>
using namespace std;

int n, tmp;
long long minCost;
vector<int> r;
vector<long long> c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	r.resize(n-1);
	for (int i = 0; i < n - 1; i++) {
		cin >> r[i];
	}
	c.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}


	for(int i = 0; i < n; i++)
	{
		tmp = n-1;
		//가스 값이 더 싼 도시 찾기
		for(int j=i; j < n; j++){
			if(c[i] > c[j]){
				tmp = j;
				break;
			}
		}

		//다음 도시까지의 길이
		long long nextCity = 0;
		for (int k = i; k < tmp; k++) {
			nextCity += r[k];
		}
		

		//다음 도시까지 필요한 가스를 충전. 현재 도시 가스가격 * 다음 도시까지의 길이
		minCost += c[i] * nextCity;

		if (tmp < n - 1)
			i = (tmp - 1);
		else
			i = n - 1;
	}

	cout << minCost;

	return 0;
}