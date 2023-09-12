#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1);
    int j = 0;

    for (long long i = left; i <= right; i++) 
    {
        int y = i / n;
        int x = i % n;   

        if (y > x) answer[j++] = y+1;
        else    answer[j++] = x+1;
    }

    return answer;
}