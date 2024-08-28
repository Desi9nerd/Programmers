#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
int F[1000001];
vector<int> v, result;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n);
	result.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		F[v[i]]++;
	}

	stack<int> st; // 스택에 인덱스를 저장
	
	for (int i = n - 1; i >= 0; i--) // 오른쪽에서 왼쪽으로 진행
	{
		int number = v[i];
		int height = F[number];

		// 스택의 top을 비교하여 스택에서 제거할 조건 확인
		while (!st.empty()) 
		{
			int topNum = v[st.top()];
			int topHeight = F[topNum];

			if (height >= topHeight) st.pop();
			else break;
		}

		result[i] = -1;

		if (!st.empty()) {
			result[i] = v[st.top()];
		}

		st.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}

	return 0;
}