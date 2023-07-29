#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int Count = 0, zeroCnt = 0, oneCnt = 0;
    
    while(s.size() > 1)
    {
        for (const auto& i : s) {
            if (i == '1')
                oneCnt++;
            else if (i == '0')
                zeroCnt++;
        }
        
        s.clear();
        while(oneCnt)
        {
            s = to_string(oneCnt % 2) + s;

            oneCnt /= 2;
        }
        
        oneCnt = 0;
        Count++;
    }
    
    answer.push_back(Count);
    answer.push_back(zeroCnt);
    
    return answer;
}