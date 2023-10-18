#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> sco, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pQ;
    for(int i=0; i<sco.size(); i++){
        pQ.push(sco[i]);
    }

    while(!pQ.empty())
    {
        if (pQ.top() >= K) break; // pQ의 모든 음식이 K이상이면 while문 종료 

        if (pQ.size() == 1 && pQ.top() < K) // pQ의 남은 음식이 1개이고 해당 음식이 K보다 작으면
            return -1; // -1 리턴

        int leastSco = pQ.top();
        pQ.pop();
        int secondSco = pQ.top();
        pQ.pop();

        int newFood = leastSco + (secondSco * 2);
        pQ.push(newFood);

        answer++;
    }

    return answer;
}