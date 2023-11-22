#include <iostream>
#include <string>
using namespace std;

bool isCorrect(string str) // '올바른 괄호 문자열'인지 검사하는 함수
{
    int cnt = 0;
    for (char ch : str) 
    {
        if (ch == '(') 
            cnt++;
        else 
            cnt--;

        if (cnt < 0) return false; // cnt가 0보다 작아지면 올바르지 않은 괄호 문자열
    }

    return cnt == 0; // 문자열의 끝까지 검사했을 때 cnt가 0이면 올바른 괄호 문자열
}

string Reverse(string str) // 괄호의 방향을 뒤집는 함수
{
    string result = "";
    for (char c : str)  
    {
        if (c == '(') 
            result += ")"; // '(' 이면 ')'로 변경
        else 
            result += "("; // ')' 이면 '('로 변경
    }

    return result; // 뒤집은 문자열 반환
}

string solve(string p) // 주어진 괄호 문자열을 올바른 괄호 문자열로 변환하는 함수
{
    if (p == "") // 예외처리: 빈 문자열이면 그대로 반환
        return p; 

    string u = "", v = "";
    int cnt = 0;
    for (int i = 0; i < p.size(); ++i) 
    {
        if (p[i] == '(') 
            cnt++;
        else 
            cnt--;

    	if (cnt == 0) // cnt가 0이 되는 지점에서 u, v 분리
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (isCorrect(u)) // u가 올바른 괄호 문자열이면
        return u + solve(v); // u와 변환된 v를 붙여서 반환
    else // u가 올바르지 않은 괄호 문자열이면
        return "(" + solve(v) + ")" + Reverse(u.substr(1, u.size() - 2)); // '(' + 변환된 v + ')' + 뒤집은 u의 가운데 부분을 반환
}

string solution(string p) {

    return solve(p);
}