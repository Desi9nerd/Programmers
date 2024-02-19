#include <cmath>

int countZeroBits(int n) // '0' ��Ʈ�� ������ ���� �Լ�
{
    int cnt = 0;

    for (int i = 0; i < 30; i++) // 30��Ʈ���� Ȯ��
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
	// �� ������ OR ������ ������� '0' ��Ʈ�� ���� ���
    int ab_cnt = countZeroBits(A | B);
    int bc_cnt = countZeroBits(B | C);
    int ac_cnt = countZeroBits(A | C);
	// �� ������ OR ������ ������� '0' ��Ʈ�� ���� ���
    int abc_cnt = countZeroBits(A | B | C);

    int answer = pow(2, a_cnt) + pow(2, b_cnt) + pow(2, c_cnt) - pow(2, ab_cnt) - pow(2, bc_cnt) - pow(2, ac_cnt) + pow(2, abc_cnt);
    
    return answer;
}
