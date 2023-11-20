#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pQ;
vector<int> dp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp.resize(n);
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		pQ.push(input);
	}

	if (n == 1) {
		cout << "0" << "\n";
		return 0;
	}
	else if (n == 2) {
		int tmp = pQ.top();
		pQ.pop();
		cout << tmp + pQ.top() << "\n";
		return 0;
	}

	dp[0] = pQ.top();
	pQ.pop();
	dp[1] = dp[0] + pQ.top();
	pQ.pop();
	pQ.push(dp[1]);
	int sum = dp[1];
	for (int i = 2; i < n; i++) {
		dp[i] = pQ.top();
		pQ.pop();
		dp[i] += pQ.top();
		pQ.pop();
		pQ.push(dp[i]);
		sum += dp[i];
	}

	cout << sum << "\n";

	return 0;
}