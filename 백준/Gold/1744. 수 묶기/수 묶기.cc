#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long answer; // 수열의 두 수를 묶었을 때 나올 수 있는 수열의 최대합
vector<int> negative, zero, positive;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int input;
	for(int i = 0; i < n; i++){
		cin >> input;
		if (input == 0) zero.push_back(input);
		else if (input < 0) negative.push_back(input);
		else if (input > 0) positive.push_back(input);
	}
	sort(negative.begin(), negative.end());
	sort(positive.rbegin(), positive.rend());

	if(negative.size() >= 2)
	{
		for (int i = 0; i < negative.size() - 1; i += 2) {
			answer += negative[i] * negative[i + 1];
		}
	}
	if (positive.size() >= 2)
	{
		for (int i = 0; i < positive.size() - 1; i += 2) {
			answer += max(positive[i] * positive[i + 1], positive[i] + positive[i + 1]);
		}
	}

	if (zero.size() == 0){ // 0의 개수 == 0
		if (negative.size() % 2 == 1) answer += negative[negative.size() - 1];
		if (positive.size() % 2 == 1) answer += positive[positive.size() - 1];
		cout << answer << "\n";
		return 0;
	}

	if (zero.size() % 2 == 0){ // 0의 개수가 짝수
		if (negative.size() % 2 == 1 && positive.size() % 2 == 1)
		{
			if (abs(negative[negative.size() - 1]) <= abs(positive[positive.size() - 1]))
				answer += negative[negative.size() - 1] + positive[positive.size() - 1];
			// else에서는 negative[negative.size() - 1] * 0 + positive[positive.size() - 1] * 0
		}
		else if (negative.size() % 2 == 1 && positive.size() % 2 == 0)
		{
			if (abs(negative[negative.size() - 1]) > positive[positive.size() - 1] * positive[positive.size() - 2])
				answer -= positive[positive.size() - 1];
			else
				answer += negative[negative.size() - 1];
		}
		else if (negative.size() % 2 == 0 && positive.size() % 2 == 1)
		{
			answer += positive[positive.size() - 1];
		}
	}
	else { // 0의 개수가 홀수
		if (negative.size() % 2 == 1 && positive.size() % 2 == 1)
		{			
			answer += negative[negative.size() - 1] * 0 + positive[positive.size() - 1];
		}
		else if (negative.size() % 2 == 1 && positive.size() % 2 == 0)
		{
			answer += negative[negative.size() - 1] * 0;
		}
		else if (negative.size() % 2 == 0 && positive.size() % 2 == 1)
		{
			answer += positive[positive.size() - 1];
		}
	}

	cout << answer << "\n";

	return 0;
}