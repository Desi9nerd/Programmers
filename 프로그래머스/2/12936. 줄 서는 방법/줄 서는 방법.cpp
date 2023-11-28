#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long k) {
    
    vector<int> answer; // 결과를 저장할 벡터 초기화
    vector<int> temp(n); 
    vector<long long> fact(n, 1); // 팩토리얼을 저장할 벡터 초기화, 첫 번째 요소는 1로 설정

    for (int i = 1; i < n; i++) // 팩토리얼 계산 (1부터 (n-1)까지)
        fact[i] = fact[i - 1] * i;

    for (int i = 0; i < n; i++) // 순열을 위한 벡터 초기화 (1부터 n까지)
        temp[i] = i + 1;

    k--; // k를 0-based 인덱스로 조정

    
    for (int i = 0; i < n; i++) // 각 위치에 대해
    {
        int idx = k / fact[n - i - 1]; // k를 현재 위치의 팩토리얼로 나눈 몫을 이용해 해당 위치에 올 숫자를 순열에서 찾음
        answer.push_back(temp[idx]);
        //printf("%d ", answer[idx]);

        temp.erase(temp.begin() + idx); // 찾은 숫자를 순열에서 제거

        k %= fact[n - i - 1]; // k를 현재 위치의 팩토리얼로 나눈 나머지로 업데이트
    }

    return answer;
}