#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer;
char x;

void Divide(const string& s, int start, int end)
{
    int xCnt = 0, yCnt = 0;
    
    for (int i = start; i < end; i++)
    {
        if (s[i] == x){
            xCnt++;
        }
        else {
            yCnt++;
        }
        
        if (xCnt == yCnt){
            //cout << "i = " << i << "\n";
            xCnt = 0; yCnt = 0;
            answer++;
            
            if (i+1 < end) x = s[i+1];
        }
    }
    
    if (xCnt != 0 || yCnt != 0) answer++;
}

int solution(string s) {
    x = s[0];
    
    Divide(s, 0, s.size());
    
    return answer;
}