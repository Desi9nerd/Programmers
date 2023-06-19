#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k, input, sum=0, maxValue=-2147000000;
	cin >> n >> k;
	vector<int> v(n);

	for(int i=0; i<n; i++){
		cin >> input;
		v[i]=input;
	}

	for(int i=0; i<k; i++){
		sum += v[i];
	}
	maxValue = sum;

	for(int i=k; i<n; i++){
		sum = sum + v[i] - v[i - k];

		if (maxValue < sum) maxValue = sum;
	}

	cout << maxValue;

	return 0;
}