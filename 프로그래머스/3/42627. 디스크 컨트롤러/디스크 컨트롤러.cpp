#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b){
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end());
    
    priority_queue<vector<int>, vector<vector<int>>, Compare> pQ;
    
    int time = 0, total = 0, idx = 0;
    while (idx < n || !pQ.empty())
    {
        for (int i = idx; i < n; i++){
            if (jobs[i][0] <= time){
                pQ.push(jobs[i]);
                idx++;
            }
            else{
                break;
            }
        }
        
        if (!pQ.empty()) // 대기 중인 작업이나 현재 바로 시작할 작업이 있는 경우 
        {
            time += pQ.top()[1];
            total += time - pQ.top()[0];
            pQ.pop();
        }
        else { // 현재 time 기준 시작할 수 있는 작업이 없는 경우 
            if (idx < n) {
                time = jobs[idx][0];  
            } 
        }        
    }
    
    return total / n;
}
