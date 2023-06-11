#include<iostream>
#include<string>
#include<set>
using namespace std;

struct Compare
{
	bool operator()(const string& a, const string& b) const
	{
		if (a.size() == b.size())
			return a < b;
		else
			return a.size() < b.size();
	}
};

int main() {
	int n;
	cin >> n;

	set<string, Compare> mySet;

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		mySet.insert(input);
	}

	for (auto j : mySet)
		cout << j << "\n";

	return 0;
}