#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(int x, int y, int n) {

	int answer = -1;
	queue<pair<int,int>> Q; // 위치, 연산 횟수

	Q.push({ y, 0 });
	while(!Q.empty())
	{
		int num = Q.front().first;
		int cnt = Q.front().second;
		Q.pop();

		if (num == x){
			answer = cnt;
			break;
		}

		if (num - n >= x) {
			Q.push({ num - n, cnt + 1 });
		}
		if (num % 2 == 0){
			Q.push({ num / 2, cnt + 1 });
		}
		if (num % 3 == 0) {
			Q.push({ num / 3, cnt + 1 });
		}
	}

	return answer;
}