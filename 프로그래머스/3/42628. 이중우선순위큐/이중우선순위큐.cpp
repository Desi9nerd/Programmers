#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> oper) {
    vector<int> answer;

    priority_queue<int> pQ;
    priority_queue<int, vector<int>, greater<int>> revpQ;

    for (int i = 0; i < oper.size(); i++)
    {
        if (oper[i][0] == 'I') {
            int num = stoi(oper[i].substr(2));
            pQ.push(num);
            revpQ.push(num);
        }
        else if (oper[i][0] == 'D') {
            if (oper[i][2] == '1') {
                if (pQ.empty()) continue;
                if (!revpQ.empty() && pQ.top() == revpQ.top()) revpQ.pop();
                pQ.pop();
            }
            else if (oper[i][2] == '-') {
                if (revpQ.empty()) continue;
                if (!pQ.empty() && pQ.top() == revpQ.top()) pQ.pop();
                revpQ.pop();
            }
        }

        if (pQ.top() < revpQ.top())
        {
            while (!pQ.empty()) pQ.pop();
            while (!revpQ.empty()) revpQ.pop();
        }
    }

    if (pQ.empty() || revpQ.empty()) {
        answer.emplace_back(0);
        answer.emplace_back(0);
    }
    else {
        answer.emplace_back(pQ.top());
        answer.emplace_back(revpQ.top());
    }

    return answer;
}