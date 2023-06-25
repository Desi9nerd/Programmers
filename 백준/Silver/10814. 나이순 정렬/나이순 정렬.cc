
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, vector<string>> myMap;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, age;
	string name;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;
		myMap[age].push_back(name);
	}

	for (auto& it : myMap)
	{
		for (auto i : it.second)
		{
			cout << it.first << " " << i << "\n";
		}
	}

	return 0;
}