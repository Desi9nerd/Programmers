#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>

using namespace std;

priority_queue<int,vector<int>,greater<int>> min_heap;
priority_queue<int> max_heap;

vector<int> solution(vector<string> arguments) {
    vector<int> answer;

    for(int i=0;i<arguments.size();i++)
    {
        string a = arguments[i];
        char o = a[0];
        int n = atoi(a.substr(2).c_str());

        if(o == 'I')
        {
            min_heap.push(n);
            max_heap.push(n);
        }
        else if(o == 'D' && n == 1)
        {
            if(max_heap.empty()) continue;
            if(max_heap.top() == min_heap.top()) min_heap.pop();
            max_heap.pop();
        }
        else if (o == 'D' && n == -1)
        {
            if(min_heap.empty()) continue;
            if(max_heap.top() == min_heap.top()) max_heap.pop();
            min_heap.pop();
        }

        if(max_heap.top() < min_heap.top())
        {
            while(!min_heap.empty()) min_heap.pop();
            while(!max_heap.empty()) max_heap.pop();
        }
    }

    if(min_heap.empty()) 
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(max_heap.top());
        answer.push_back(min_heap.top());
    }

    return answer;
}