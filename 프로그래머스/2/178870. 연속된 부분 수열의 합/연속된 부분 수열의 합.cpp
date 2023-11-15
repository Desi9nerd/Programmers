#include <vector>
using namespace std;

vector<int> solution(vector<int> seq, int k) {
    vector<int> answer(2, -1); // 조건을 만족하는 부분 수열의 시작Idx와 끝Idx 담기

	int dif = 2147000000;
    int n = seq.size();
    seq.resize(n + 1);

    int start = 0, end = 0, sum = 0;
    while(end < n+1)
    {
        if (sum == k)
        {
            if (end - start < dif) {
                dif = end - start;
                answer[0] = start;
                answer[1] = end-1;

                if (dif == 0) break;
            }

            sum -= seq[start++];
        }
        else if (sum > k)
        {
            sum -= seq[start++];
        }
        else if (sum < k)
        {
            sum += seq[end++];
        }
    }
    
    return answer;
}