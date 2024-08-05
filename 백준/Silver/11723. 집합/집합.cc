#include <iostream>
using namespace std;

int m;
int answer;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> m;
	string input;
	int x;
	for (int i = 0; i < m; i++)
	{
		cin >> input;

		if (input == "add"){
			cin >> x;
			answer |= (1 << x);
		}
		else if (input == "remove"){
			cin >> x;
			answer &= ~(1 << x);
		}
		else if (input == "check") {
			cin >> x;

			if (answer & (1 << x)){
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (input == "toggle") {
			cin >> x;
			answer ^= (1 << x);
		}
		else if (input == "all") {
			answer |= ((1 << 21) - 1);
		}
		else if (input == "empty") {
			answer &= ~((1 << 21) - 1);
		}
	}

	return 0;
}
