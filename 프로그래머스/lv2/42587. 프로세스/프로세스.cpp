#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    
    queue<pair<int,int>> Q;
    priority_queue<int> pQ;

    for (int i = 0; i < priorities.size(); i++) {
        Q.push({priorities[i], i});
        pQ.push(priorities[i]);
    }

    int answer = 1;

    while(!Q.empty())
    {
        if(Q.front().first == pQ.top())
        {
            if (Q.front().second == location) {
                return answer;
            }
            Q.pop();
            pQ.pop();
            answer++;            
        }
        else
        {
            pair<int,int> tmp = Q.front();
            Q.pop();
            Q.push(tmp);
        }
    }

    return answer;
}
