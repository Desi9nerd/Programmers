#include <string>
#include <deque>
using namespace std;

string solution(string number, int k) {
    deque<char> dq;
    for (int i = 0; i < number.size(); i++) {
        while (!dq.empty() && dq.back() < number[i] && k > 0) {
            dq.pop_back();
            k--;
        }
        dq.push_back(number[i]);
    }

    while (k--) {
        dq.pop_back();
    }

    string answer = "";
    while (!dq.empty()) {
        answer += dq.front();
        dq.pop_front();
    }

    return answer;
}