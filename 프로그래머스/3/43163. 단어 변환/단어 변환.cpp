#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int answer = 987654321;
int n, len;
vector<int> ch;

bool canChange(const string& str1, const string& str2)
{
    int diffCount = 0;
    
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            diffCount++;
        }
        if (diffCount > 1) {
            return false;
        }
    }
    
    return diffCount == 1;
}

void DFS(string str, const string& target, const vector<string>& words, int cnt)
{
    //cout << str << ", " << target << "\n";
    
    if (str == target){
        //cout << "cnt = " << cnt << "\n";
        answer = min(answer, cnt);
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (ch[i] == 0 && canChange(str, words[i]))
        {
            ch[i] = 1;
            DFS(words[i], target, words, cnt + 1);
            ch[i] = 0;
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    len = begin.size();
    n = words.size();
    ch.resize(n);
    
    DFS(begin, target, words, 0);
    
    answer = answer == 987654321 ? 0 : answer;
    
    return answer;
}