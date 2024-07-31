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

void Generate(int idx, string str, const vector<int> ch)
{
	if (idx == input.size()){
		results.insert(str);
		return;
	}

	if (ch[idx] == 1) // idx 위치의 문자 생략
	{
		Generate(idx + 1, str, ch);
	}
	else // 문자 생략X
	{
		Generate(idx + 1, str + input[idx], ch);
	}
}

void CalHelper(int cnt, vector<int>& ch)
{
	if (cnt == brackets.size()) {
		Generate(0, "", ch);
		return;
	}

	// 현재 괄호 쌍을 제거하지 않는 경우
	CalHelper(cnt + 1, ch);

	// 현재 괄호 쌍을 제거하는 경우
	ch[brackets[cnt].first] = 1;
	ch[brackets[cnt].second] = 1;
	CalHelper(cnt + 1, ch);
	ch[brackets[cnt].first] = 0;
	ch[brackets[cnt].second] = 0;
}

void Cal()
{
	vector<int> ch(n, 0);

	CalHelper(0, ch);
}

//void Cal()
//{
//	for (int bitmask = 1; bitmask < (1 << brackets.size()); bitmask++)
//	{
//		vector<int> ch(n, 0);
//
//		for (int i = 0; i < brackets.size(); i++)
//		{
//			if (bitmask & (1 << i)) {
//				ch[brackets[i].first] = 1;
//				ch[brackets[i].second] = 1;
//			}
//		}
//
//		Generate(0, "", ch);
//	}
//}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> input;
	n = input.size();

	FindBrackets();
	Cal();

	int i = 0;
	for (const auto& iter : results)
	{
		i++;
		if (i == 1) continue;
		cout << iter << "\n";
	}

	return 0;
}