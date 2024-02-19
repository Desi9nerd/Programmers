#include <cmath>

int countZeroBits(int n) // '0' 비트의 개수를 세는 함수
{
    int cnt = 0;

    for (int i = 0; i < 30; i++) // 30비트까지 확인
    {
        if ((n & (1 << i)) == 0) {
            cnt++;
        }
    }

    return cnt;
}

int solution(int A, int B, int C) {
    int a_cnt = countZeroBits(A);
    int b_cnt = countZeroBits(B);
    int c_cnt = countZeroBits(C);
	// 두 정수를 OR 연산한 결과에서 '0' 비트의 개수 계산
    int ab_cnt = countZeroBits(A | B);
    int bc_cnt = countZeroBits(B | C);
    int ac_cnt = countZeroBits(A | C);
	// 세 정수를 OR 연산한 결과에서 '0' 비트의 개수 계산
    int abc_cnt = countZeroBits(A | B | C);

    int answer = pow(2, a_cnt) + pow(2, b_cnt) + pow(2, c_cnt) - pow(2, ab_cnt) - pow(2, bc_cnt) - pow(2, ac_cnt) + pow(2, abc_cnt);
    
    return answer;
}
