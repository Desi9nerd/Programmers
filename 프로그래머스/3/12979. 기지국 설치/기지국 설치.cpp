#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int x = 0;
    int block = w + 1 + w;
    int cnt = 0;
    int position = 1;

    for (int i = 0; i < stations.size(); i++) 
    {
        // 기지국이 설치된 범위의 시작과 끝
        int start = max(1, stations[i] - w);
        int end = min(n, stations[i] + w);

        // 기지국이 설치된 범위 이전의 빈 공간 계산
        if (position < start) {
            cnt = start - position;
            if (cnt > 0) {
                if (cnt % block == 0) answer += (cnt / block);
                else answer += (cnt / block + 1);
            }
        }

        // 다음 조사 시작 지점을 기지국 설치 범위 이후로 설정
        position = end + 1;
    }

    // 마지막 기지국 이후의 빈 공간 계산
    if (position <= n) {
        cnt = n - position + 1;
        if (cnt > 0) {
            if (cnt % block == 0) answer += (cnt / block);
            else answer += (cnt / block + 1);
        }
    }

    return answer;
}