#include <vector>
#include <algorithm>
using namespace std;

bool Check(vector<int>& A, int k) // Check 함수는 주어진 배열 A에서 k보다 크거나 같은 연속된 숫자의 개수가 k보다 크거나 같은지를 확인하는 함수
{
    int i = 0;
    while (i < A.size()) 
    {
        int j = i;
        
        while (j < A.size() && A[j] >= k) { // j는 i부터 시작해서 A[j]가 k보다 크거나 같은 동안 j를 증가
            j++;
        }
       
        // 만약 j - i가 k보다 크거나 같다면, k보다 크거나 같은 연속된 숫자의 개수가 k보다 크거나 같다는 것이므로 true를 반환
        if (j - i >= k)  
            return true;

        i = max(j, i + 1); // j가 i + 1보다 크다면 i를 j로 설정하고, 그렇지 않다면 i를 하나 증가
    }

    return false; // 위의 조건을 만족하는 k가 없다면 false를 반환
}

int solution(vector<int> &A) // 배열 A에서 가장 큰 k를 찾는 함수
{
    int lt = 1;
    int rt = A.size();
    
    while (lt < rt) // 이진 탐색을 사용하여 lt와 rt 사이에서 k를 찾음
    {
        int mid = (lt + rt + 1) / 2;

        if (Check(A, mid)) // Check(A, mid)가 true라면, mid보다 크거나 같은 k가 있다는 의미이므로 lt를 mid로 설정
            lt = mid;
        else // 그렇지 않다면, mid보다 큰 k가 없다는 의미이므로 rt를 mid - 1로 설정
            rt = mid - 1;
    }

    return lt; // lt는 조건을 만족하는 가장 큰 k다
}
