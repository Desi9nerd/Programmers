#include <iostream>
#include <queue>
using namespace std;

int n;
long long x;
priority_queue<long long, vector<long long>, greater<long long>> pQ;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;

		if (x == 0) {
			if (!pQ.empty())
			{
				cout << pQ.top() << "\n";
				pQ.pop();
			}
			else
				cout << "0" << "\n";
		}
		else if (x > 0) {
			pQ.push(x);
		}
	}


	return 0;
}
