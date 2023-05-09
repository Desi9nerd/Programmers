#include <iostream>
#include<map>
#include<string>
using namespace std;

int main() {
	int n, m, cnt = 0;
	cin >> n >> m;

	map<string, bool> word;

	for (int i = 0; i < n; i++) {
		string s1;
		cin >> s1;
		word[s1] = true;
	}

	for (int i = 0; i < m; i++) {
		string s2;
		cin >> s2;

		if (word[s2] == true) cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}