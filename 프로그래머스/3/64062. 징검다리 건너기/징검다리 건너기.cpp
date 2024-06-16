#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

// 연속된 k개의 징검다리의 각각의 수가 낮은거 찾아야 함
// 처음부터 k개씩 묶은 후 가장 높은 수를 기록하며, k개씩 묶었을때 가장 큰 수의 숫자가 전체 묶음 중 가장 작은 것을 구함.

int solution(vector<int> stones, int k) {
    int answer = 2147000000;
    deque<int> dQ; // 구간 내 돌의 자리 인덱스. front에 최대값의 인덱스가 자리함.
    int maxNum = 0;
    
    for (int i = 0; i < k; i++)
    {
        while(!dQ.empty() && stones[dQ.back()] <= stones[i]){
            dQ.pop_back();
        }
        dQ.push_back(i);
    }
    answer = min(answer, stones[dQ.front()]);
    
    for (int i = k; i < stones.size(); i++)
    {
        if (!dQ.empty() && dQ.front() <= i - k) {
            dQ.pop_front();
        }
        
        while(!dQ.empty() && stones[dQ.back()] <= stones[i]){
            dQ.pop_back();
        }
        dQ.push_back(i);
        
        answer = min(answer, stones[dQ.front()]);
    }
    
    return answer;
}