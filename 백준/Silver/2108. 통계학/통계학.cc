#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

bool Comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, input, maxNum = -4001, minNum = 4001;
	double sum = 0;
	cin >> n;
	vector<int> v(n);
	map<int, int> myMap;

	for (int i = 0; i < n; i++) {
		cin >> input;
		v[i] = input;
		sum += input;
		myMap[input]++;
		if (maxNum < v[i]) maxNum = v[i];
		if (minNum > v[i]) minNum = v[i];
	}

	//산술평균
	if (round(sum / n) == 0)
		cout << "0" << "\n";
	else
		cout << round(sum / n) << "\n";

	//중앙값
	sort(v.begin(), v.end());
	cout << v[n / 2] << "\n";

	//최빈값
	vector<pair<int, int>> vec(myMap.begin(), myMap.end());
	sort(vec.begin(), vec.end(), Comp);

	if (n > 1 && vec[0].second == vec[1].second)
		cout << vec[1].first << "\n";
	else
		cout << vec[0].first << "\n";

	//범위
	cout << maxNum - minNum << "\n";

	return 0;
}
