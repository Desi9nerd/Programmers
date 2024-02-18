#include <algorithm>

int answer;

int solution(int N) {

    int n = N;
    int k = 0;
    while(n){
        n /= 2;
        k++;
    }

    int cnt = 0;
    for(int i = k-1; i >= 0; i--) // 앞자리수부터 1 확인하기 위해 k-1부터 시작
    {
        if(N & (1 << i)){
            answer = max(answer, cnt);
            cnt = 0;
        }
        else{
            cnt++;
        }
    }

    return answer;
}
