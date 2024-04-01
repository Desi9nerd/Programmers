#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string name) {

	int answer = 0; // 상하 조작 횟수
    int CursorMove = name.size() - 1; // 최소 좌우 조작 횟수. 최악의 경우는 모든 문자를 순차적으로 방문하는 것.

	for (int i = 0; i < name.size(); i++)
	{
        answer += min(name[i] - 'A', 'Z' - name[i] + 1); // 각 자리의 알파벳을 A로 만드는데 필요한 최소 횟수 계산

        int j = i + 1;
        while (j < name.size()) // 'A'가 연속되는 부분의 끝을 찾음
        {
            if (name[j] == 'A') j++;
            else break;
        }

        // i에서 시작하여 좌우로 이동했을 때의 총 이동 거리 계산
        int LengthToEnd = (name.size()-1) - j + 1;
        int TotalMovment = min(2 * i + LengthToEnd, i + 2 * LengthToEnd);

        CursorMove = min(CursorMove, TotalMovment); // 최소 좌우 조작 횟수 업데이트
	}

    return answer + CursorMove; // 상하 조작 횟수와 좌우 조작 횟수의 합 반환
}