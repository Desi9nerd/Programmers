#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(9, vector<int>(9));
vector<int> row(9);
vector<int> column(9);

// 현재 위치 (y, x)에 newNum을 놓았을 때 유효한지 행, 열, 3x3 작은 사각형을 검사하는 함수
bool isSafe(int y, int x, int newNum)
{
	// 행, 열 검사
	for (int i = 0; i < 9; i++)
	{
		if (v[i][x] == newNum || v[y][i] == newNum)
			return false;
	}

	// 3x3 작은 사각형 검사
	int newY = y / 3 * 3;
	int newX = x / 3 * 3;
	for(int i = newY; i < newY + 3; i++){
		for (int j = newX; j < newX + 3; j++)
		{
			if (v[i][j] == newNum)
				return false;
		}
	}

	return true;
}

//DP를 활용한 스도쿠 완성
bool Solve()
{
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) 
		{
			//빈칸인지 체크
			if (v[y][x] == 0)
			{
				//현재 위치에 숫자를 놓을 때
				for (int newNum = 1; newNum <= 9; newNum++) 
				{	// 현재 위치에 newNum을 놓을 수 있는지 검사
					if (isSafe(y, x, newNum)) 
					{ 
						v[y][x] = newNum;

						// 재귀적으로 다음 빈 칸에 대해 시도
						if (Solve()) return true;

						// 유효하지 않은 경우, 백트래킹 수행: 칸을 비우고 이전 빈 칸으로 돌아감
						v[y][x] = 0;

					}//if
				}//for newNum

				return false;				
			}//if
		}//for x
	}//for y

	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	bool flag = false;
	for(int y=0; y < 9; y++){
		for (int x = 0; x < 9; x++) {
			cin >> v[y][x];

			if (v[y][x] == 0) flag = true;				
		}
	}

	//빈칸이 하나라도 있으면
	if(flag == true)
	{
		//스도쿠 문제 풀기
		Solve();		
	}

	//스도쿠 출력
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			cout << v[y][x] << " ";
		}
		cout << "\n";
	}

	return 0;
}