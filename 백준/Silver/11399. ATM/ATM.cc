#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n), P(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	P[0] = v[0];
	int sum = P[0];
	for (int i = 1; i < n; i++) {
		P[i] = P[i - 1] + v[i];
		sum += P[i];
	}

	cout << sum;

	return 0;
}