#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Data {
	int start; int end; int dist;

	Data(int a, int b, int c) {
		start = a;
		end = b;
		dist = c;
	}
	// 끝점이 같으면 시작점이 작은 것이 먼저 오게 하고, 그렇지 않으면 끝점이 작은 것이 먼저 오게 한다.
	bool operator<(const Data& oper) const {
		if (end == oper.end)
			return start < oper.start;

		return end < oper.end;
	}
};

int n, d; // n: 데이터의 개수, d: 거리의 최대값.
vector<Data> v;
int answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		if (a <= b) v.push_back({ a, b, b - a });
		else v.push_back({ b, a, a - b });
	}
	cin >> d;
	sort(v.begin(), v.end());


	priority_queue<int> pQ;

	for (int i = 0; i < n; i++) 
	{
		int start = v[i].start;
		int end = v[i].end;

		if (end - start > d) continue;

		pQ.push(-start); //pQ는 내림차순 정렬. 오름차순 정렬을 변경하지 않고 내림차순으로 사용하기 위해 start의 값에 -부호를 붙여 넣어주어 원하는 순서로 정렬함

		while (!pQ.empty()) 
		{
			if (-pQ.top() + d >= end) break;

			pQ.pop();
		}

		answer = max(answer, (int)pQ.size());
	}


	cout << answer;

	return 0;
}