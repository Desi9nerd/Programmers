#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

string input; // 문제에서 주어진 문자열
int n;
vector<pair<int, int>> brackets; // 괄호 한 쌍의 위치를 저장
set<string> results; // 만들 수 있는 문자열을 기록

void FindBrackets()
{
	stack<int> bracketLocation;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '('){
			bracketLocation.push(i);
		}
		else if (input[i] == ')'){
			int openBracketLocation = bracketLocation.top();
			bracketLocation.pop();

			brackets.push_back({ openBracketLocation, i });
		}
	}
}

void Generate(int idx, string str, const vector<bool> ch)
{
	if (idx == n){
		results.insert(str);
		return;
	}

	if (ch[idx]) // idx 위치의 문자 생략
	{
		Generate(idx + 1, str, ch);
	}
	else // 문자 생략X
	{
		Generate(idx + 1, str + input[idx], ch);
	}
}

void Cal()
{
	for (int bitmask = 1; bitmask < (1 << brackets.size()); bitmask++)
	{
		vector<bool> ch(n, false);

		for (int i = 0; i < brackets.size(); i++)
		{
			if (bitmask & (1 << i)) {
				ch[brackets[i].first] = true;
				ch[brackets[i].second] = true;
			}
		}

		Generate(0, "", ch);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> input;
	n = input.size();

	FindBrackets();
	Cal();

	for (const auto& iter : results)
	{
		cout << iter << "\n";
	}

	return 0;
}