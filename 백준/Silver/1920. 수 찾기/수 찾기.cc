#include <iostream>
#include <set>
using namespace std;

set<long long> mySet;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m;

	cin >> n;
	for(int i=0; i<n; i++){
		long long input;
		cin >> input;
		mySet.emplace(input);
	}

	cin >> m;
	for (int i = 0; i < m; i++){
		long long value;
		cin >> value;

		auto it = mySet.find(value);
		if (it != mySet.end()) cout << "1" << "\n";
		else cout << "0" << "\n";
	}

	return 0;
}