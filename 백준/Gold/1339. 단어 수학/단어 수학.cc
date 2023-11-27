#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int n;
vector<string> word;
map<char, int> myMap;

bool Compare(const pair<char, int>& a, const pair<char, int>& b)
{
	return a.second > b.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	word.resize(n);
	for(int i=0; i<n; i++){
		cin >> word[i];

		int m = word[i].size();
		for(int j = 0; j < m; j++)
		{
			if (myMap.find(word[i][j]) != myMap.end())
				myMap[word[i][j]] += pow(10, (m - 1) - j);
			else
				myMap.insert({word[i][j], pow(10, (m-1) - j)});
		}
	}

	vector<pair<char, int>> v;
	for(const auto& iter : myMap){
		v.push_back(iter);
	}

	sort(v.begin(), v.end(), Compare);

	//for (const auto& iter : v)
	//	cout << iter.first << " " << iter.second << "\n";

	int answer = 0;
	int number = 9;
	for(int i = 0; i < v.size(); i++)
	{
		answer += v[i].second * number;
		number--;
	}

	cout << answer << "\n";

	return 0;
}