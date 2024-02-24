#include <set>
#include <algorithm>

int solution(vector<int> &A) {
    set<int> mySet;

    for(int i = 0; i < A.size(); i++){
        mySet.insert(abs(A[i]));
    }
    int cnt = mySet.size();

    return cnt;
}
