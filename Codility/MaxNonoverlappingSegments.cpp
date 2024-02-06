#include <vector>

int solution(vector<int> &A, vector<int> &B) {
    
    int n = A.size();
    if(n == 0) return 0;
    else if(n == 1) return 1;

    int answer = 1;
    int cur = B[0]; // cur는 현재 비교 기준이 되는 B 벡터의 요소이며 초기값은 B의 첫 번째 요소
    
    for(int i = 1; i < n; i++) // 첫 번째 요소는 이미 처리했으므로 두 번째 요소부터 마지막 요소까지 반복
    {
        if(A[i] > cur){  // 만약 A의 i번째 요소가 cur보다 크면
            cur = B[i];  // cur를 B의 i번째 요소로 갱신
            answer++;	 // answer를 1 증가
        }
    }

    return answer;
}
