#include <string>
#include <vector>
using namespace std;

// n: 진법, t: 미리 구할 숫자의 갯수(튜브가 말해야 하는 숫자의 개수), m: 게임에 참가하는 인원, p: 튜브의 순서

string Convert(int k, int n) // k: 주어진 숫자, n: 진법
{
    if (k == 0) return "0";
    if (n == 10) return to_string(k);

    string tmp;
	while (k > 0)
	{
        string newNum; // 진법 계산 후 나머지 값
        if (k % n < 10) // 나머지가 10보다 작으면
            newNum = to_string(k % n);
        else{ // 나머지가 10 이상이면
            newNum = 'A' + (k % n - 10);
        }

        tmp = newNum + tmp;
        k /= n;
	}
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    string s;
    for(int i=0; i<t*m; i++)
    {
        s = s + Convert(i, n);
    }

    for(int i = 1; i <= s.size(); i++)
    {
    	if(i % m == p) // 튜브의 순서
            answer += s[i-1];
        else if (i % m == 0 && m == p) // 튜브의 순서, 마지막 순서인 경우 나머지가 0이므로
            answer += s[i - 1];
	    
        if (answer.size() == t) 
            break;
    }

    return answer;
}