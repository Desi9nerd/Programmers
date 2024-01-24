#include <iostream>
using namespace std;

long long digit[10]; // 0부터 9까지 각 자릿수가 등장하는 횟수를 저장

// 주어진 숫자 n에서 각 자릿수가 얼마나 많이 등장하는지 계산하는 함수
void Cal(long long n, long long ten)
{
    while (n > 0) {
        digit[n % 10] += ten;
        n = n / 10;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long start = 1;
    long long end;
    long long ten = 1; // 10의 거듭제곱 값을 저장하는 변수
    cin >> end;

    while (start <= end) 
    {
        while (start % 10 != 0 && start <= end) {
            Cal(start, ten); // 시작 숫자에서 각 자릿수가 얼마나 많이 등장하는지 계산
            start += 1;
        }

        if (start > end) break; // 시작 숫자가 끝 숫자보다 크면 반복을 종료

        while (end % 10 != 9 && start <= end) {
            Cal(end, ten); // 끝 숫자에서 각 자릿수가 얼마나 많이 등장하는지 계산
            end -= 1;
        }


        long long cnt = (end / 10 - start / 10 + 1); // 시작 숫자와 끝 숫자 사이에 있는 숫자의 개수를 계산

    	for (int i = 0; i <= 9; i++) { // 0부터 9까지의 각 자릿수에 대해
            digit[i] += cnt * ten; // 등장 횟수를 누적 
        }

        start = start / 10;
        end = end / 10;
        ten = ten * 10; // 10의 거듭제곱 값을 업데이트
    }

    for (int i = 0; i <= 9; i++) {
        cout << digit[i] << " ";
    }

    return 0;
}
