#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v, dpF, dpB;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n);
	dpF.resize(n, 1);	dpB.resize(n, 1);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}

	int answer = 1; 
	dpF[0] = 1;
	dpB[n-1] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (v[j] < v[i] && dpF[i] < dpF[j] + 1) {
				dpF[i] = dpF[j] + 1;
			}
		}
	}

	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] > v[j] && dpB[i] < dpB[j] + 1) {
				dpB[i] = dpB[j] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (answer < dpF[i] + dpB[i] - 1) answer = dpF[i] + dpB[i] - 1;
	}

	cout << answer;

	return 0;
}