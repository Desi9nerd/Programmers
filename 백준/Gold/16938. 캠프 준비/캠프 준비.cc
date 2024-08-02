#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int n, l, r, x;
vector<int> A;
int answer;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l >> r >> x;
	A.resize(n);
	for (int i = 0; i < n; i++){
		cin >> A[i];
	}

	for (int bitmask = 1; bitmask < (1 << n); bitmask++)
	{
		int sumProblems = 0;
		int easiest = 987654321, hardest = 0;

		for (int i = 0; i < n; i++)
		{
			if (bitmask & (1 << i))
			{
				sumProblems += A[i];
				easiest = min(easiest, A[i]);
				hardest = max(hardest, A[i]);
			}
		}

		if (l <= sumProblems && sumProblems <= r && (hardest - easiest) >= x){
			answer++;
		}
	}

	cout << answer;

	return 0;
}