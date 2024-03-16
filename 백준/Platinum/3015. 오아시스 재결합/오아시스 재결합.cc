#include <iostream>
#include <stack>
using namespace std;

struct Info {
	int height, pair;
};

int n;
long long answer;
stack<Info> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int input;

	for (int i = 0; i < n; i++) {
		cin >> input;

		while (!st.empty() && st.top().height < input) { 
			answer += st.top().pair;
			st.pop();
		}

		int sameHeight = 1;
		if (!st.empty())
		{			
			if (st.top().height == input) { // 바로 앞 사람과 새로 선 사람의 키가 같은 경우
				answer += st.top().pair;
				sameHeight = st.top().pair + 1;

				if (st.size() > 1) answer++;

				st.pop();
			}
			else if (st.top().height > input) { // 바로 앞 사람이 새로 선 사람보다 큰 경우
				answer += 1; 
			}
		}

		st.push({ input, sameHeight });
	}

	cout << answer;

	return 0;
}