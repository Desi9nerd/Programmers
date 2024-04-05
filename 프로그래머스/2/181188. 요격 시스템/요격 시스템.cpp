#include <algorithm>
#include <vector>
using namespace std;

bool Compare(const vector<int>& a, const vector<int>& b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> tg) {
    int n = tg.size();

    sort(tg.begin(), tg.end(), Compare);

    int answer = 0;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (tg[i][0] < last) continue;
        
        last = tg[i][1];
        answer++;
    }

    return answer;
}