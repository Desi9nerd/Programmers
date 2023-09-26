#include <string>
#include <vector>
using namespace std;

bool isPrime(long long x)
{
    if (x <= 1)
        return false;

    if (x == 2 || x == 3)
        return true;

    if (x % 2 == 0 || x % 3 == 0)
        return false;

    for (long long i = 5; i * i <= x; ++i)
    {
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;

	string cNum = "";
    while(n>0)
    {
        string temp = to_string(n % k);
        cNum = temp + cNum;

        n /= k;
    }
    //cout << cNum << "\n"; //Debugging

    string tmp = "";
    long long tmpNum = -1;
    for(int i=0; i<cNum.size()+1; i++)
    {
        if (cNum[i] == '0' || cNum[i] == '\0')
        {
            //cout << "tmp = " << tmp << "\n"; //Debugging
            
            if (tmp != "") {
                tmpNum = stol(tmp);
            }
            //cout << "tmpNum = " << tmpNum << "\n"; //Debugging

            if(isPrime(tmpNum) == true)
            {
                for (int j = 2; j < tmpNum; j++) {
                    if (tmpNum % j == 0) {
                        break;
                    }
                }                
                answer++; //위에서 break 안 걸렸다면 소수
            }           

        	tmp = "";
            tmpNum = -1;
        }
        else
        {
            tmp = tmp + cNum[i];
        }        
    }


    return answer;
}