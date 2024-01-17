#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Spec {
	int weight; int value;
};

bool Compare(Spec a, Spec b) {
	return a.weight < b.weight; // 오름차순. 무게가 가벼운 순으로 정렬
}

int n, k; // n: 보석 수, k: 가방 수
vector<Spec> gem; // 무게, 가격
vector<int> bag; // 각 가방에 담을 수 있는 최대 무게

long long answer; // 훔칠 수 있는 보석의 최대 가격

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	gem.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> gem[i].weight >> gem[i].value;
	}
	bag.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}
	sort(gem.begin(), gem.end(), Compare); // 오름차순. 무게가 가벼운 순으로 정렬
	sort(bag.begin(), bag.end()); // 오름차순. 가벼운 가방 순서로 정렬

	priority_queue<int> pQ; // 가격이 높은 순으로 보석을 저장할 우선순위 큐
	int idx = 0; // 현재 보석의 인덱스
	
	for (int i = 0; i < k; i++) 
	{	
		// 현재 가방에 담을 수 있는 보석들을 우선순위 큐에 넣음
		while (idx < n && gem[idx].weight <= bag[i])
		{
			pQ.push(gem[idx].value);
			idx++;
		}

		// 우선순위 큐에서 가장 가치가 높은 보석을 꺼냄 (가방에 넣음)
		if (!pQ.empty()) {
			answer += pQ.top();
			pQ.pop();
		}
	}

	cout << answer << "\n";

	return 0;
}