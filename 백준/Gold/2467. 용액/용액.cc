#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> Acid, Alkali;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	int neutral = 2147000000;
	int p1 = 0, pp1 = 0;
	int p2 = n - 1, pp2 = n - 1;
	while (p1 < p2)
	{
		int sum = v[p1] + v[p2];

		if (abs(sum) <= abs(neutral)) {
			neutral = sum;
			pp1 = p1;
			pp2 = p2;
		}

		if (abs(v[p1]) < abs(v[p2])) p2--;
		else p1++;
	}

	cout << v[pp1] << " " << v[pp2];

	return 0;
}