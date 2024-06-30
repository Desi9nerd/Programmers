#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> pQ;

    int total = 0;
    for(int i = 0; i < works.size(); i++){
        total += works[i];
        pQ.push(works[i]);
    }

    if (total <= n) return 0;

    while (!pQ.empty() && n > 0)
    {
        int top = pQ.top();
        pQ.pop();

        n--;
        top--;
        pQ.push(top);
    }

    while(!pQ.empty())
    {
        int top = pQ.top();
        pQ.pop();
        cout << "top = " << top << "\n";
        answer += pow(top, 2);
    }


    return answer;
}
