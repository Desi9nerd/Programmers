#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int h = 0; //h: H-Index
    int n = citations.size(); //n: 발표한 논문의 수
    sort(citations.rbegin(), citations.rend());

    for (int i = 0; i < n; i++)
    {
         if (citations[i] > i)
            h = i + 1;
        else
            break;
    }


    return h;
}
