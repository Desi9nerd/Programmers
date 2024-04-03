#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int answer; // 최대 점수를 저장할 변수
vector<int> dice(10);     // 주사위 눈금
vector<int> player(4);    // 4개의 말이 위치한 칸의 번호

vector<int> location(34); // 각 칸에서 다음 칸으로 이동할 때의 인덱스
vector<int> score(34);    // 각 칸의 점수
vector<int> turn(34);     // 파란색 화살표가 있는 칸에서 다른 경로로 바꿀 인덱스
vector<bool> bPresent(34, false); // 각 칸에 말이 존재하는지 여부

void BackT(int cnt, int sum)
{
    if (cnt == 10) { // 주사위를 모두 사용했을 때
        answer = max(answer, sum); // 최대 점수 갱신
        return;
    }

    for (int i = 0; i < 4; i++) // 4개의 말에 대해 반복
    {
        int prev = player[i]; // 현재 말의 위치
        int cur = prev;
        int move = dice[cnt]; // 이번에 이동할 주사위 눈금

        if (turn[cur] > 0) { // 현재 위치가 파란색 화살표 지점이라면
            cur = turn[cur]; // 경로 전환
            move--;          // 이동 횟수 1 감소
        }

        while (move--) { // 남은 이동횟수만큼 이동
            cur = location[cur];
        }

        if (cur != 21 && bPresent[cur]) continue; // 도착 칸이 아니고, 이미 다른 말이 있는 칸이라면 이동 불가

        bPresent[prev] = false; // 이전 위치를 비움
        bPresent[cur] = true;   // 현재 위치에 말을 놓음
        player[i] = cur;        // 말의 위치 갱신

        BackT(cnt + 1, sum + score[cur]); // 재귀 호출로 다음 주사위 눈금 처리

        // 백트래킹을 위해 상태 복원
        player[i] = prev;
        bPresent[prev] = true;
        bPresent[cur] = false;
    }
}

void GivenInfo()
{
    // 윷놀이 판의 기본 구성 설정
    for (int i = 0; i < 27; i++) {
        location[i] = i + 1;
    }
    location[21] = 21; // 도착 칸 설정

    // 특수 경로 설정
    location[27] = 20; location[28] = 29; location[29] = 30;
    location[30] = 25; location[31] = 32; location[32] = 25;

    // 파란색 화살표가 있는 칸에서 다른 경로로 전환하는 설정
    turn[5] = 22; turn[10] = 31; turn[15] = 28;

    // 각 칸의 점수 설정
    for (int i = 0; i < 21; i++) {
        score[i] = 2 * i;
    }
    // 특수 경로의 점수 설정
	score[22] = 13; score[23] = 16; score[24] = 19;
	score[25] = 25; score[26] = 30; score[27] = 35;
	score[28] = 28; score[29] = 27; score[30] = 26;
	score[31] = 22; score[32] = 24;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	GivenInfo();

	for (int i = 0; i < 10; i++){
		cin >> dice[i];
	}

	BackT(0, 0);

	cout << answer << "\n";
	return 0;
}