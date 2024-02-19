#include <string>
#include <stack>
using namespace std;

string solution(string& S) {
    stack<char> st;

    if(S.size() == 0) return "";

    st.push(S[0]);
    int i = 1;

    while (i < S.size())
    {
        if (!st.empty() && S[i] == st.top()) {
            st.pop();
            i++;
        }
        else {
            st.push(S[i]);
            i++;
        }
    }

    string answer = "";
    while (!st.empty()) {
        answer = st.top() + answer;
        st.pop();
    }

    return answer;
}
