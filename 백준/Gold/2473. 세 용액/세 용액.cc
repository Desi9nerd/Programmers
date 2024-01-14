#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
long long answer = 3000000000;
int res1, res2, res3;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());


	for(int i = 1; i < n - 1; i++)
	{
		int p1 = 0, p2 = n - 1;
		while (p1 < i && i < p2)
		{
			long long sum = (long long)v[p1] + v[i] + v[p2];

			if (abs(sum) < abs(answer)) {
				answer = sum;
				res1 = v[p1];
				res2 = v[i];
				res3 = v[p2];
			}

			if (sum < 0) {
				p1++;
			}
			else {
				p2--;
			}
		}
	}

	cout << res1 << " " << res2 << " " << res3 << "\n";

	return 0;
}
