#include<iostream>
#include<queue>
using namespace std;

priority_queue<long long> pQ;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	long long input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;

		if (input == 0) {
			if (pQ.empty()) cout << "0" << "\n";
			else {
				cout << pQ.top() << "\n";
				pQ.pop();
			}
		}
		else {
			pQ.push(input);
		}
	}


	return 0;
}