#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;

	int pos = 0; 
	cin >> pos;

	cout << S[pos - 1] << "\n";
	return 0;
}