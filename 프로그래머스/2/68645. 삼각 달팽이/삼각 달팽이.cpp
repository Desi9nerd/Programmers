#include <string>
#include <vector>
using namespace std;

int ch[1001][1001];

void Tri(int y, int x, int n) // (y, x)는 시작위치
{
	int val = ch[y][x];
	for (int i = 0; i < n; i++) {
		ch[y + i][x] = val++;
	}
	for (int i = 1; i < n; i++) {
		ch[y + n - 1][x + i] = val++;
	}
	for (int i = 1; i < n - 1; i++) {
		ch[y + n - 1 - i][x + n - 1 - i] = val++;
	}

	if (ch[y + 2][x + 1] == 0)
		ch[y + 2][x + 1] = ch[y + 1][x + 1] + 1;
}

vector<int> solution(int n) {
	int size = n;

	ch[0][0] = 1;

	int y = 0, x = 0;
	for (int i = n; i > 0; i -= 3) {
		Tri(y, x, i);
		y += 2;
		x += 1;
	}

	vector<int> answer;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(ch[i][j] != 0)
				answer.push_back(ch[i][j]);
		}
	}

	return answer;
}