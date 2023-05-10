#include<iostream>
#include<map>
#include<string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	map<int, string> name1;
	map<string, int> name2;

	for (int i = 1; i <= n; i++) {
		string str1;
		cin >> str1;

		name1[i] = str1;
		name2[str1] = i;
		//name1.insert({ i, str });
		//name2.insert({ str, i });
	}

	for (int i = 1; i <= m; i++) {
		string str2;
		cin >> str2;

		//숫자
		if (isdigit(str2[0]))
			cout << name1[stoi(str2)] << '\n';
		//문자
		else
			cout << name2[str2] << '\n';
	}

	return 0;
}