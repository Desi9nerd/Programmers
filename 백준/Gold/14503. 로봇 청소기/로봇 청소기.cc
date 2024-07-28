#include <iostream>
#include <vector>
using namespace std;

int dirY[4] = { -1, 0, 1, 0 };
int dirX[4] = { 0, 1, 0, -1 };

int n, m;
int currY, currX, currDir;
vector<vector<int>> v;
int answer; // 청소하는 칸의 개수


bool Move(int y, int x, int dir)
{
	// 4 방향 체크 
	for (int i = 0; i < 4; i++) {
		int nextDir = (dir + 3 - i) % 4;  // 왼쪽으로 돌기
		int ny = y + dirY[nextDir];
		int nx = x + dirX[nextDir];

		if (ny < 0 || n <= ny || nx < 0 || m <= nx) continue;

		if (v[ny][nx] == 0){
			v[ny][nx] = -1;
			answer++;
			currY = ny, currX = nx, currDir = nextDir;
			return true;
		}
	}

	if (dir == 0 && y + 1 < n && v[y + 1][x] != 1){
		currY = y + 1, currX = x, currDir = dir;
		return true;
	}
	else if (dir == 1 && 0 <= x - 1 && v[y][x - 1] != 1){
		currY = y, currX = x - 1, currDir = dir;
		return true;
	}
	else if (dir == 2 && 0 <= y - 1 && v[y - 1][x] != 1){
		currY = y - 1, currX = x, currDir = dir;
		return true;
	}
	else if (dir == 3 && x + 1 < m && v[y][x + 1] != 1){
		currY = y, currX = x + 1, currDir = dir;
		return true;
	}

	return false;
}

void Clean(int y, int x, int dir)
{
	//cout << y << ", " << x << ", dir = " << dir << "\n";

	if (Move(y, x, dir)){

		Clean(currY, currX, currDir);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	v.resize(n, vector<int>(m));
	cin >> currY >> currX >> currDir;
	for (int y = 0; y < n; y++){
		for (int x = 0; x < m; x++) {
			cin >> v[y][x];
		}
	}

	// 시작 칸이 아직 청소되지 않은 경우, 시작 칸을 청소
	if (v[currY][currX] == 0) {
		v[currY][currX] = -1;
		answer++;
	}

	Clean(currY, currX, currDir);

	cout << answer;

	return 0;
}