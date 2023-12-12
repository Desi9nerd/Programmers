#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, k;
	cin >> t;

	while (t--)
	{
		cin >> k;
		multiset<int> mset;
		priority_queue<int> pQ1;
		priority_queue<int, vector<int>, greater<int>> pQ2;

		char input;
		int inputNum;
		for (int i = 0; i < k; i++) {
			cin >> input >> inputNum;

			if (input == 'I') {
				mset.insert(inputNum);
				pQ1.push(inputNum);
				pQ2.push(inputNum);
			}
			else {
				if (mset.empty()) continue;
				if (inputNum == 1) {
					mset.erase(mset.find(pQ1.top()));
					pQ1.pop();
				}
				else {
					mset.erase(mset.find(pQ2.top()));
					pQ2.pop();
				}
				while (!pQ1.empty() && mset.find(pQ1.top()) == mset.end())
					pQ1.pop();
				while (!pQ2.empty() && mset.find(pQ2.top()) == mset.end())
					pQ2.pop();
			}
		}

		if (mset.empty())
			cout << "EMPTY" << "\n";
		else
			cout << *mset.rbegin() << " " << *mset.begin() << "\n";
	}

	return 0;
}