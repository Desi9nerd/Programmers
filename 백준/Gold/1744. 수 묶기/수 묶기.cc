#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long answer; // 수열의 두 수를 묶었을 때 나올 수 있는 수열의 최대합
vector<int> negative, positive;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int input;
	for(int i = 0; i < n; i++){
		cin >> input;
		if (input <= 0) negative.push_back(input); // 0과 음수를 negative 벡터에 넣음
		else if (input > 1) positive.push_back(input); // 1보다 큰 수를 positive 벡터에 넣음
		else answer += 1; // 1은 미리 더해줌
	}
	
	sort(negative.begin(), negative.end()); // negative 벡터를 오름차순으로 정렬
	sort(positive.rbegin(), positive.rend()); // positive 벡터를 내림차순으로 정렬

	if(negative.size() % 2 == 1) { // negative 벡터의 크기가 홀수라면
		answer += negative.back();
		negative.pop_back();
	}
	while(negative.size() >= 2) { // 음수 묶기
		long long first = negative.back(); negative.pop_back();
		long long second = negative.back(); negative.pop_back();
		answer += first * second;
	}

	if(positive.size() % 2 == 1) { // positive 벡터의 크기가 홀수라면
		answer += positive.back();
		positive.pop_back();
	}
	while(positive.size() >= 2) { // 양수 묶기
		long long first = positive.back(); positive.pop_back();
		long long second = positive.back(); positive.pop_back();
		answer += first * second;
	}

	cout << answer << "\n";

	return 0;
}
