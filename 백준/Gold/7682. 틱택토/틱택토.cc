#include <iostream>
#include <vector>
using namespace std;

//vector<string> v;
//int r, c;
//
//bool TikTakToc(int ny, int nx)
//{
//	if (ny + 3 >= r || nx + 3 >= c) return false;
//
//	// 가로 틱택토
//	if (v[ny][nx] != '.' && v[ny][nx] == v[ny][nx + 1] == v[ny][nx + 2]) return false;
//	if (v[ny + 1][nx] != '.' && v[ny + 1][nx] == v[ny + 1][nx + 1] == v[ny + 1][nx + 2]) return false;
//	if (v[ny + 2][nx] != '.' && v[ny + 2][nx] == v[ny + 2][nx + 1] == v[ny + 2][nx + 2]) return false;
//
//	// 세로 틱택토
//	if (v[ny][nx] != '.' && v[ny][nx] == v[ny + 1][nx] == v[ny + 2][nx]) return false;
//	if (v[ny][nx + 1] != '.' && v[ny][nx + 1] == v[ny + 1][nx + 1] == v[ny + 2][nx + 1]) return false;
//	if (v[ny][nx + 2] != '.' && v[ny][nx + 2] == v[ny + 1][nx + 2] == v[ny + 2][nx + 2]) return false;
//
//	// 대각선 틱택토
//	if (v[ny + 1][nx + 1] != '.' && v[ny][nx] == v[ny + 1][nx + 1] == v[ny + 2][nx + 2]) return false;
//	if (v[ny + 1][nx + 1] != '.' && v[ny + 2][nx] == v[ny + 1][nx + 1] == v[ny][nx + 2]) return false;
//
//	// 입력이 꽉찬 경우
//	int Xnum = 0, Onum = 0;
//	for (int y = ny; y < ny + 3; y++){
//		for (int x = nx; x < nx + 3; x++) {
//			if (v[y][x] == 'X'){
//				Xnum++;
//			}
//			else if (v[y][x] == 'O') {
//				Onum++;
//			}
//		}
//	}
//	if (Xnum + Onum == 9) return false;
//
//	return true;
//}
//
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0); cout.tie(0);
//
//	string input;
//	while(cin){
//		cin >> input;
//		if (input == "end") break;
//		v.emplace_back(input);
//	}
//
//	r = v.size();
//	c = v[0].size();
//
//	int nr = r - (r % 3);
//	int nc = c - (c % 3);
//
//	for (int i = 0; i < r; i += 3){
//		for (int j = 0; j < c; j += 3)
//		{
//			if (TikTakToc(i, j))
//				cout << "valid" << "\n";
//			else
//				cout << "invalid" << "\n";
//		}
//	}
//
//
//	return 0;
//}


vector<string> v;

bool isWin(int ny, int nx, char player)
{
	// 가로 틱택토
	if (v[ny][nx] == player && v[ny][nx] == v[ny][nx + 1] && v[ny][nx + 1] == v[ny][nx + 2]) return true;
	if (v[ny][nx + 3] == player && v[ny][nx + 3] == v[ny][nx + 4] && v[ny][nx + 4] == v[ny][nx + 5]) return true;
	if (v[ny][nx + 6] == player && v[ny][nx + 6] == v[ny][nx + 7] && v[ny][nx + 7] == v[ny][nx + 8]) return true;

	// 세로 틱택토
	if (v[ny][nx] == player && v[ny][nx] == v[ny][nx + 3] && v[ny][nx + 3] == v[ny][nx + 6]) return true;
	if (v[ny][nx + 1] == player && v[ny][nx + 1] == v[ny][nx + 4] && v[ny][nx + 4] == v[ny][nx + 7]) return true;
	if (v[ny][nx + 2] == player && v[ny][nx + 2] == v[ny][nx + 5] && v[ny][nx + 5] == v[ny][nx + 8]) return true;

	// 대각선 틱택토
	if (v[ny][nx] == player && v[ny][nx] == v[ny][nx + 4] && v[ny][nx + 4] == v[ny][nx + 8]) return true;
	if (v[ny][nx + 2] == player && v[ny][nx + 2] == v[ny][nx + 4] && v[ny][nx + 4] == v[ny][nx + 6]) return true;

	return false;
}

bool TikTakToc(int ny, int nx)
{
	int Xnum = 0, Onum = 0;
	for (int i = 0; i < 9; i++) {
		if (v[ny][i] == 'X') Xnum++;
		else if (v[ny][i] == 'O') Onum++;
	}

	if (Xnum != Onum && Xnum != Onum + 1) return false;

	bool Xwin = isWin(ny, nx, 'X');
	bool Owin = isWin(ny, nx, 'O');

	if (Xwin && Owin) return false;
	if (Xwin && Xnum == Onum) return false;
	if (Owin && Xnum > Onum) return false;
	if (!Xwin && !Owin && Xnum + Onum != 9) return false;

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string input;
	while (cin >> input) {
		if (input == "end") break;
		v.emplace_back(input);
	}
	
	for (int i = 0; i < v.size(); i++) {
		if (TikTakToc(i, 0))
			cout << "valid" << "\n";
		else
			cout << "invalid" << "\n";
	}


	return 0;
}