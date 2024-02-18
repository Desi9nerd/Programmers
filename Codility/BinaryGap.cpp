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
    for(int i = k-1; i >= 0; i--) // ���ڸ������� 1 Ȯ���ϱ� ���� k-1���� ����
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
