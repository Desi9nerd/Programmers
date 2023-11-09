#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    int n = number.size();
    int remain = n - k; // 남아야하는 숫자 개수

    int start = 0;  // 탐색을 시작할 인덱스

    for (int i = 0; i < remain; i++)  // 남아야 하는 숫자의 개수만큼 반복
    {
        char maxNum = number[start];
        int maxIdx = start;

        // start부터 k+i까지 반복하며 최대 숫자와 그 인덱스 찾기
        for (int j = start; j <= k + i; j++) 
        {
            if (maxNum < number[j]) {
                maxNum = number[j];
                maxIdx = j;
            }
        }

        start = maxIdx + 1; // start를 최대값 숫자의 다음 인덱스로 갱신

        answer += maxNum;  // 최대값 숫자를 결과 문자열에 추가
    }

    return answer;
}