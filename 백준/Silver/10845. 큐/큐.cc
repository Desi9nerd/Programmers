#include <iostream>
#include <queue>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
 
	int n, x;
	queue<int> Q;
	string input;
	cin >> n;
 
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "push") {
			cin >> x;
			Q.push(x);
		}
		else if (input == "pop") {
			if (Q.empty()) cout << -1 << '\n';
			else {
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (input == "size") {
			cout << Q.size() << '\n';
		}
		else if (input == "empty") {
			cout << Q.empty() << '\n';
		}
		else if (input == "front") {
			if (Q.empty()) cout << -1 << '\n';
			else cout << Q.front() << '\n';
		}
		else if (input == "back") {
			if (Q.empty()) cout << -1 << '\n';
			else cout << Q.back() << '\n';
		}
	}
 
	return 0;
}