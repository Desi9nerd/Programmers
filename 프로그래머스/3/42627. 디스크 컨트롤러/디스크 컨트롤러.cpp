#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 비교 함수 객체
struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1]; // 소요 시간이 작은 순으로 정렬
    }
};

int solution(vector<vector<int>> jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end()); // 요청 시간 기준으로 정렬

    priority_queue<vector<int>, vector<vector<int>>, Compare> pQ;
    int answer = 0, i = 0, time = 0;

    while (i < jobs.size() || !pQ.empty()) 
    {
        // 현재 시간에서 실행 가능한 모든 작업을 큐에 넣음
        while (i < jobs.size() && time >= jobs[i][0]) {
            pQ.push(jobs[i++]);
        }

        if (!pQ.empty()) { 
            vector<int> job = pQ.top();
            pQ.pop();
            time += job[1];              // 작업 소요 시간을 더함
            answer += time - job[0];     // 작업 종료 시간 - 작업 요청 시간 = 대기 시간
        } 
        else {
            time = jobs[i][0];           // 다음 작업의 요청 시간으로 시간 설정
        }
    }

    return answer / n; // 평균 대기 시간 반환
}
