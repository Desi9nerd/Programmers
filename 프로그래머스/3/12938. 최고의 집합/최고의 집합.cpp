#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    int value = s / n;
    int remainder = s % n;
    int x = n - remainder;

    if (value < 1)
    {
        answer.push_back(-1);
        return answer;
    }

    for (int i = 1; i <= n; i++)
    {
        if (i > x){
            answer.push_back(value + 1);
        }
        else{
            answer.push_back(value);
        }
    }


    return answer;
}