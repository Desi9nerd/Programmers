#include <queue>
#include <map>
#include <algorithm>

int solution(vector<int> &A) {
    
    int n = A.size();
    queue<int> Q;
    map<int, int> myMap;

    for(int i = 0; i < n; i++){
        Q.push(A[i]);
        if(myMap.find(A[i]) != myMap.end()){
            myMap[A[i]]++;
        }
        else{
            myMap[A[i]] = 1;
        }
    }

    int answer = -1;
    while(!Q.empty())
    {
        int front = Q.front();
        Q.pop();

        if(myMap[front] == 1){
            answer = front;
            break;
        }
    }

    return answer;
}
