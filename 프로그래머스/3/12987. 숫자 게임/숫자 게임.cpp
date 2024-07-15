#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int answer = 0;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[p1] < B[p2]){
            p1++; p2++;
            answer++;
        }
        else { // A[p1] >= B[p2]
            p2++;
        }
    }

    return answer;
}
