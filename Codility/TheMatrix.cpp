#include <vector>
#include <algorithm>
using namespace std;

bool Check(vector<int>& A, int k) // Check �Լ��� �־��� �迭 A���� k���� ũ�ų� ���� ���ӵ� ������ ������ k���� ũ�ų� �������� Ȯ���ϴ� �Լ�
{
    int i = 0;
    while (i < A.size()) 
    {
        int j = i;
        
        while (j < A.size() && A[j] >= k) { // j�� i���� �����ؼ� A[j]�� k���� ũ�ų� ���� ���� j�� ����
            j++;
        }
       
        // ���� j - i�� k���� ũ�ų� ���ٸ�, k���� ũ�ų� ���� ���ӵ� ������ ������ k���� ũ�ų� ���ٴ� ���̹Ƿ� true�� ��ȯ
        if (j - i >= k)  
            return true;

        i = max(j, i + 1); // j�� i + 1���� ũ�ٸ� i�� j�� �����ϰ�, �׷��� �ʴٸ� i�� �ϳ� ����
    }

    return false; // ���� ������ �����ϴ� k�� ���ٸ� false�� ��ȯ
}

int solution(vector<int> &A) // �迭 A���� ���� ū k�� ã�� �Լ�
{
    int lt = 1;
    int rt = A.size();
    
    while (lt < rt) // ���� Ž���� ����Ͽ� lt�� rt ���̿��� k�� ã��
    {
        int mid = (lt + rt + 1) / 2;

        if (Check(A, mid)) // Check(A, mid)�� true���, mid���� ũ�ų� ���� k�� �ִٴ� �ǹ��̹Ƿ� lt�� mid�� ����
            lt = mid;
        else // �׷��� �ʴٸ�, mid���� ū k�� ���ٴ� �ǹ��̹Ƿ� rt�� mid - 1�� ����
            rt = mid - 1;
    }

    return lt; // lt�� ������ �����ϴ� ���� ū k��
}
