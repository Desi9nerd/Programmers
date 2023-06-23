#include <iostream>
#include <unordered_map>
using namespace std;

int n, m, input, card;
unordered_map<int, int> unMap;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> input;
		unMap[input]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> card;

		cout << unMap[card]<< " ";
	}

	return 0;
}