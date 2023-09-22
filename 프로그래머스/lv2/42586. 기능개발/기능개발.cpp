#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> myStack;

    for(int i= progresses.size()-1; i>=0; i--){
        int x = (100-progresses[i]) / speeds[i] + ((100-progresses[i]) % speeds[i] != 0);
        myStack.push(x);
    }
       
    while(!myStack.empty())
    {
        int prev = myStack.top();
        myStack.pop();
        int cnt = 1;

        if(!myStack.empty())
        {
            while (prev >= myStack.top())
            {
                myStack.pop();
                cnt++;

                if (myStack.empty()) break;
            }
        }       

        answer.push_back(cnt);
    }
    

    return answer;
}