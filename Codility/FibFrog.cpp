#include <algorithm>
#include <vector>
using namespace std;

const int INT_MAX = 2147000000;

vector<int> fib;

void Fibonacci(int k)
{
    fib.push_back(0);
    fib.push_back(1);

    while (fib.back() < k) {
        fib.push_back(fib.end()[-1] + fib.end()[-2]);
    }
}

int solution(vector<int> &A) {
    int n = A.size();
    
    A.insert(A.begin(), 1); // �������� �����ϴ� ����
    A.push_back(1); 		// �������� �����ϴ� ����

    Fibonacci(n+2);
   
    vector<int> jumps(n+2, -1);
    jumps[0] = 0;

    for (int i = 1; i < n+2; i++) // �� ��ġ������ �ּ� ������ ���ϱ�
    {
        if (A[i] == 0) continue;

        int min_jump = INT_MAX;
        for (const auto& iter : fib) 
        {
            if (iter > i) break;

            if (jumps[i-iter] != -1) {
                min_jump = min(min_jump, jumps[i-iter] + 1);
            }
        }

        if (min_jump != INT_MAX) {
            jumps[i] = min_jump;
        }
    }

    return jumps[n+1];
}
