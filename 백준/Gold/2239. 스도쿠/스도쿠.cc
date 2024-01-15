#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(9, vector<int>(9));
vector<pair<int, int>> zero;

bool isPossible(int y, int x, int select)
{
	// (y, x)에 select 숫자를 놓을때 해당 행과 열에 select과 같은 숫자가 있는지 체크
	for (int i = 0; i < 9; i++) {
		if (v[i][x] == select) return false;
		if (v[y][i] == select) return false;
	}

	// 작은 사각형 내에 select 숫자가 있는지 체크
	int ny = y - y % 3;
	int nx = x - x % 3;
	for (int y = ny; y < ny + 3; y++) {
		for (int x = nx; x < nx + 3; x++) {
			if (v[y][x] == select) return false;
		}
	}
	return true;
}

void Sudo(int cnt)
{
	if (cnt == zero.size()) { // 모든 빈칸을 채웠다면 출력하고 종료
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				cout << v[y][x];
			}
			cout << "\n";
		}
		exit(0); // 정답을 찾으면 프로그램 종료
	}

	int y = zero[cnt].first;
	int x = zero[cnt].second;
	for (int i = 1; i <= 9; i++) {
		if (isPossible(y, x, i)) {
			v[y][x] = i;
			Sudo(cnt + 1); // 다음 빈칸을 채우러 간다
			v[y][x] = 0; // 되돌리기
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string input;
	for (int y = 0; y < 9; y++) {
		cin >> input;
		for (int x = 0; x < 9; x++) {
			v[y][x] = input[x] - '0';
			if (v[y][x] == 0) zero.push_back({ y, x });
		}
	}

	Sudo(0);

	return 0;
}