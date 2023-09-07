
#include <vector>
#include <string>
#include <deque>
#include <stack>
using namespace std;

bool isMatch(char a, char b)
{
	if (a == '[' && b == ']') return true;
	if (a == '{' && b == '}') return true;
	if (a == '(' && b == ')') return true;

	return false;
}

int solution(string s) {
	int answer = 0;
	int n = s.size();

	deque<char> DQ(s.begin(),s.end()); //왼쪽 회전을 용이하게 하기위해 deque 사용.

	while(n--)
	{
		stack<char> st; //괄호의 순서를 체크하기 위해 사용하는 stack
	
		//현재의 문자열이 올바른 괄호 문자열인지 확인하기 위해 st을 이용한다.
		for (char bracket : DQ) //DQ의 요소들을 순회 
		{
			if (bracket == '[' || bracket == '{' || bracket == '(')
				st.push(bracket);
			
			else 
			{	// st가 비워져있고 다음 괄호가 ']', '}', ')' 라면
				// st의 맨 위 원소와 다음 괄호가 같지 않다면
				if(st.empty() || isMatch(st.top(), bracket) == false)
				{
					st.push(bracket);	// 괄호를 st에 넣고
					break;				// 종료
				}
				// 위의 조건이 아니라면
				// =st.top의 괄호와 대응되는 괄호가 있으면 st에서 꺼낸다.
				st.pop();
			}
		}

		if (st.empty()) answer++; //stack이 비었으면 올바른 괄호 문자열이다.

		//왼쪽으로 회전
		char temp = DQ.front();
		DQ.pop_front();
		DQ.push_back(temp);
	}


	return answer;
}