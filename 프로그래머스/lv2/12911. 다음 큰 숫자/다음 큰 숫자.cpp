#include <string>
#include <vector>

using namespace std;

int BinaryCount(int n)
{
    int cnt = 0;
    string bdigit;
    while (n > 0)
    {
        if (n % 2 == 1) cnt++;

        bdigit = to_string(n % 2) + bdigit;

        n /= 2;
    }

    return cnt;
}

int solution(int n) {
    int answer = 0;

    int x = BinaryCount(n);//1의 개수

    while(n++)
    {
        if (BinaryCount(n) == x)
            break;
    }

    answer = n;


    return answer;
}