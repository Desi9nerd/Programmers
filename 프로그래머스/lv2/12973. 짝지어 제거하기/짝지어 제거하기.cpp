#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    
    int answer = -1;
    
    stack<char> st; // 중복되지 않은 문자를 저장하기 위한 스택

    for (int i = 0; i < s.size(); ++i) 
    {
        if (st.empty()) { // 스택이 비어있으면 문자 추가
            st.push(s[i]);
            continue;
        }
        
        if (st.top() == s[i]) { // 스택의 top이 현재 문자와 같으면 스택에서 삭제
            st.pop();
        }
        else { // 스택의 top과 현재 문자가 다른 경우 스택에 추가
            st.push(s[i]);
        }
    }
    
     // 스택 비어있으면 1, 그렇지 않으면 0 반환
    answer = st.empty() ? 1 : 0;
    
    return answer;
}