#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string S;
	cin >> S;
	char input;
	int n, r1, r2, cnt;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input >> r1 >> r2;

		cnt = 0;
		for (int j = r1; j < r2 + 1; j++)
		{
			if (S[j] == input) cnt++;
		}
		cout << cnt << "\n";
	}


	return 0;
}