#include <iostream>
#include <vector>
using namespace std;

int n;
long long b;
vector<vector<long long>> ori;

// 두 행렬의 곱셈 연산을 수행하는 함수
vector<vector<long long>> Calculate(vector<vector<long long>> a, vector<vector<long long>> b)
{
	vector<vector<long long>> temp(n, vector<long long>(n, 0));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			for (int k = 0; k < n; k++) {
				temp[y][x] += (a[y][k] * b[k][x]);
			}
			temp[y][x] %= 1000;
		}
	}

	return temp;
}

vector<vector<long long>> Power(long long exponent)
{
	// 지수 = 1인 경우
	if (exponent == 1){
		vector<vector<long long>> tmp(n, vector<long long>(n));
		tmp = ori;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				if (tmp[y][x] >= 1000)
					tmp[y][x] %= 1000;
			}
		}
		return tmp;
	}

	// 지수가 홀수
	else if(exponent % 2 == 1){
		return Calculate(ori, Power(exponent - 1));
	}
	// 지수가 짝수
	else{
		vector<vector<long long>> tmp = Power(exponent / 2);
		return Calculate(tmp, tmp);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> b;
	ori.resize(n, vector<long long>(n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> ori[i][j];
		}
	}

	vector<vector<long long>> result = Power(b);

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cout << result[y][x] << " ";
		}
		cout << "\n";
	}

	return 0;
}