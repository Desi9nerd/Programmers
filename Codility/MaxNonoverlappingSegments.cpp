#include <vector>

int solution(vector<int> &A, vector<int> &B) {
    
    int n = A.size();
    if(n == 0) return 0;
    else if(n == 1) return 1;

    int answer = 1;
    int cur = B[0]; // cur�� ���� �� ������ �Ǵ� B ������ ����̸� �ʱⰪ�� B�� ù ��° ���
    
    for(int i = 1; i < n; i++) // ù ��° ��Ҵ� �̹� ó�������Ƿ� �� ��° ��Һ��� ������ ��ұ��� �ݺ�
    {
        if(A[i] > cur){  // ���� A�� i��° ��Ұ� cur���� ũ��
            cur = B[i];  // cur�� B�� i��° ��ҷ� ����
            answer++;	 // answer�� 1 ����
        }
    }

    return answer;
}
