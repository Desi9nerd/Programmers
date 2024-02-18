#include <string>
#include <vector>
using namespace std;

bool CheckOne(long long x) // 주어진 인덱스에 해당하는 문자가 '1'인지 확인하는 함수
{
    // 5보다 작은 경우, 2를 제외하고는 모두 '1'에 해당
    if (x < 5 && x != 2) return true;

    // 5로 나누어 떨어지는 경우는 '0'에 해당
    if ((x - 2) % 5 == 0) return false;

    // 위의 경우에 해당하지 않으면, x를 5로 나눈 몫에 대해 재귀 호출
    return CheckOne(x / 5);
}

long long solution(int n, long long l, long long r) {
    
    int answer = 0;

    for (long long i = l-1; i < r; i++) { // l부터 r까지 각 인덱스에 대해 '1'인지 확인
        if (CheckOne(i)) answer++; // '1'이면 answer 증가
    }

    return answer;
}