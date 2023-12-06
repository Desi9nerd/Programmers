#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int n, m; // n: 사다리 수, m: 뱀의 수
map<int, int> ladder, snake;
int ch[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		cin >> ladder[input];
	}
	for (int i = 0; i < m; i++) {
		cin >> input;
		cin >> snake[input];
	}

	queue<int> Q;
	Q.push(1);
	ch[1] = 0; // 출발 위치는 이동 횟수 0으로 초기화

	while (!Q.empty())
	{
		if (Q.front() == 100) break;

		int front = Q.front();
		Q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int newLoc = front + i; // +1 ~ 6 주사위 굴려서 갈 수 있는 위치

			if (newLoc > 100) continue; // 게임 판을 벗어나는 경우는 제외

			if (ch[newLoc] == 0) // 방문하지 않은 위치인 경우
			{
				ch[newLoc] = ch[front] + 1; // 방문 체크 및 이동 횟수 기록

				if (ladder.find(newLoc) != ladder.end()) // 사다리를 만난 경우
				{
					Q.push(ladder[newLoc]);
					if (ch[ladder[newLoc]] == 0) { // 사다리를 통해 이동한 위치를 아직 방문하지 않았다면
						ch[ladder[newLoc]] = ch[newLoc]; // 방문 체크 및 이동 횟수 기록
					}
				}
				else if (snake.find(newLoc) != snake.end()) // 뱀을 만난 경우
				{
					Q.push(snake[newLoc]);
					if (ch[snake[newLoc]] == 0) { // 뱀을 통해 이동한 위치를 아직 방문하지 않았다면
						ch[snake[newLoc]] = ch[newLoc]; // 방문 체크 및 이동 횟수 기록
					}
				}
				else // 일반적인 경우
				{
					Q.push(newLoc);
				}
			}
		}
	}

	cout << ch[100] << endl;

	return 0;
}
