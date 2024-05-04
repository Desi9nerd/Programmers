#include <iostream>
#include <vector>
using namespace std;

int n, m;
int startX, startY;
int k; // 명령의 개수
vector<vector<int>> v;
vector<int> dice(6);

//    [0]
// [4][1][5]
//    [2]
//    [3]

void Roll(int dir)
{
	vector<int> tmp(6);

	if (dir == 1){ // 동
		tmp[0] = dice[0];
		tmp[1] = dice[4];
		tmp[2] = dice[2];
		tmp[3] = dice[5];
		tmp[4] = dice[3];
		tmp[5] = dice[1];
	}
	else if (dir == 2){ // 서
		tmp[0] = dice[0];
		tmp[1] = dice[5];
		tmp[2] = dice[2];
		tmp[3] = dice[4];
		tmp[4] = dice[1];
		tmp[5] = dice[3];
	}
	else if (dir == 3) { // 북
		tmp[0] = dice[1];
		tmp[1] = dice[2];
		tmp[2] = dice[3];
		tmp[3] = dice[0];
		tmp[4] = dice[4];
		tmp[5] = dice[5];
	}
	else if (dir == 4) { // 남
		tmp[0] = dice[3];
		tmp[1] = dice[0];
		tmp[2] = dice[1];
		tmp[3] = dice[2];
		tmp[4] = dice[4];
		tmp[5] = dice[5];
	}
	
	dice = tmp;
}

void Move(int dir)
{
	int x = startX;
	int y = startY;

	if (dir == 1){
		y++;
	}
	else if (dir == 2) {
		y--;
	}
	else if (dir == 3) {
		x--;
	}
	else if (dir == 4) {
		x++;
	}

	// 범위를 벋어난 경우
	if (x < 0 || n <= x || y < 0 || m <= y) return;

	// 범위 내인 경우
	Roll(dir);

	if (v[x][y] == 0){
		v[x][y] = dice[1];
	}
	else{
		dice[1] = v[x][y];
		v[x][y] = 0;
	}

	startX = x;
	startY = y;

	cout << dice[3] << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> startX >> startY >> k;
	v.resize(n, vector<int>(m));
	int input;
	for (int x = 0; x < n; x++){
		for (int y = 0; y < m; y++){
			cin >> input;
			v[x][y] = input;
		}
	}

	int dir;
	for (int i = 0; i < k; i++){
		cin >> dir;
		Move(dir);
	}

	return 0;
}