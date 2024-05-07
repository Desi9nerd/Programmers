#include <iostream>
#include <vector>
using namespace std;

int dirY[4] = { 0, -1, 0, 1 };
int dirX[4] = { 1, 0, -1, 0 };

int n; // 커브의 개수
vector<vector<int>> v(101, vector<int>(101));

int CountSquare()
{
	int answer = 0;
	for (int y = 0; y < 100; y++){
		for (int x = 0; x < 100; x++) {
			if (v[y][x] == 1 && v[y][x+1] == 1 && v[y+1][x] == 1 && v[y+1][x+1] == 1){
				answer++;
			}
		}
	}
	return answer;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++){
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		// 세대별 방향 계산
		vector<int> dots;
		dots.push_back(d); // 최초의 방향 추가
		for (int j = 0; j < g; j++)
		{
			int size = dots.size();
			for (int k = size - 1; k >= 0; k--){
				dots.push_back((dots[k] + 1) % 4);
			}
		}

		// 점 찍기
		v[y][x] = 1; // 시작점
		for (int j = 0; j < dots.size(); j++){
			y += dirY[dots[j]]; // y를 업데이트
			x += dirX[dots[j]]; // x를 업데이트

			v[y][x] = 1; // 업데이트된 위치에 점을 찍음
		}
	}

	cout << CountSquare();

	return 0;
}