#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <string>
using namespace std;

string input;
set<string> results;
vector<pair<int, int>> brackets;

void Generate(int idx, string str, vector<int>& ch)
{
	if (idx == input.size()){
		results.insert(str);
		return;
	}

	if (ch[idx] == 1){
		Generate(idx + 1, str, ch);
	}
	else if (ch[idx] == 0){
		Generate(idx + 1, str + input[idx], ch);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> input;

	// 괄호 위치 구하기
	stack<int> bracketLoc;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '('){
			bracketLoc.push(i);
		}
		else if (input[i] == ')'){
			int openLoc = bracketLoc.top();
			bracketLoc.pop();
			brackets.push_back({ openLoc, i });
		}
	}

	// 전체 경우의 수 1 << brackets.size() - 1 
	for (int bitmask = 1; bitmask < (1 << brackets.size()); bitmask++)
	{
		vector<int> ch(input.size(), 0);

		for (int i = 0; i < brackets.size(); i++)
		{
			if (bitmask & (1 << i)){
				ch[brackets[i].first] = 1;
				ch[brackets[i].second] = 1;
			}
		}

		Generate(0, "", ch);
	}

	// 결과 출력
	for (const auto& iter : results){
		cout << iter << "\n";
	}

	return 0;
}