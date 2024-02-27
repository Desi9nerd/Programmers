#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = s.size();
    int n = s.size();

    string rep = "";
    for (int i = 1; i <= n/2; i++) 
    {
        int sum = 0;
        int cnt = 1;
        
        string prev = s.substr(0, i);
        for (int j = i; j+i <= n; j += i)
        {
            string temp = s.substr(j, i);
            
            if (prev == temp) {
                cnt++;
            }
            else {
                sum += i;
                if (cnt > 1) {
                    sum += to_string(cnt).size();
                }

                prev = temp;
                cnt = 1;
            }
        }

        sum += i;
        if (cnt > 1) {
            sum += to_string(cnt).size();
        }

        if (n % i != 0) {
            sum += n % i;
        }

        answer = min(answer, sum);
    }


    return answer;
}