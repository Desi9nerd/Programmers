#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> oper) {
    vector<int> answer;

    deque<int> dQ;

    for (int i = 0; i < oper.size(); i++)
    {
        if (oper[i][0] == 'I') {
            int num = stoi(oper[i].substr(2));
            dQ.push_back(num);
            sort(dQ.begin(), dQ.end());
        }
        else if (oper[i][0] == 'D') {
            if (oper[i][2] == '1') {
                if (!dQ.empty()) dQ.pop_back();
            }
            else if (oper[i][2] == '-') {
                if (!dQ.empty()) dQ.pop_front();
            }
        }
    }

    if (dQ.empty()) {
        answer.emplace_back(0);
        answer.emplace_back(0);
    }
    else {
        answer.emplace_back(dQ.back());
        answer.emplace_back(dQ.front());
    }
    
    return answer;
}