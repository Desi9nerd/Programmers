#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isNewWord = true;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {   //빈 공백 확인
            answer.push_back(' ');
            isNewWord = true;
        }
        else if (isNewWord) {
            if ('a' <= s[i] && s[i] <= 'z') {
                answer.push_back(s[i] - 'a' + 'A');
            } else {
                answer.push_back(s[i]);
            }
            isNewWord = false;
        }
        else {
            if ('A' <= s[i] && s[i] <= 'Z') {
                answer.push_back(s[i] - 'A' + 'a');
            } else {
                answer.push_back(s[i]);
            }
        }
    }
    return answer;
}