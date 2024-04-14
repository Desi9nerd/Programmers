#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t; // 테스트 케이스의 개수
int n; // 성냥개비의 개수
int num[10] = { 2, 5, 5, 4, 5, 6, 3, 7, 6, 6 };

string MinNum(int x){
	if (x == 2) return "1";
	else if (x == 3) return "7";
	else if (x == 4) return "4";
	else if (x == 5) return "2";
	else if (x == 6) return "6";
	else if (x == 7) return "8";
	else if (x == 8) return "10";
	else if (x == 9) return "18";
	else if (x == 10) return "22"; // 반례: x == 17일때, 228(X) 200(O)
	else if (x == 11) return "20";
	else if (x == 12) return "28";
	else if (x == 13) return "68";

	int a = x / 7;
	int b = x % 7;

	string minNum = "";
	if (b == 0) {
		while (a--) {
			minNum = minNum + "8";
		}
	}
	else {
		a--;
		if (b == 1) {
			while (a--) {
				minNum = minNum + "8";
			}
			minNum = "10" + minNum;
		}
		else if (b == 2) {
			while (a--) {
				minNum = minNum + "8";
			}
			minNum = "18" + minNum;
		}
		else if (b == 3) {
			a--;
			while (a--) {
				minNum = minNum + "8";
			}
			minNum = "200" + minNum;
		}
		else if (b == 4) {
			while (a--) {
				minNum = minNum + "8";
			}
			minNum = "20" + minNum;
		}
		else if (b == 5) {
			while (a--) {
				minNum = minNum + "8";
			}
			minNum = "28" + minNum;
		}
		else if (b == 6) {
			while (a--) {
				minNum = minNum + "8";
			}
			minNum = "68" + minNum;
		}
	}

	return minNum;
}

string MaxNum(int x){
	if (x == 2) return "1";
	else if (x == 3) return "7";

	int a = x / 2;

	string maxNum = "";
	if (x % 2 == 0) {
		while (a--){
			maxNum = maxNum + "1";
		}
	}
	else { // x % 2 == 1
		a--;
		while (a--) {
			maxNum = maxNum + "1";
		}
		maxNum = "7" + maxNum;
	}

	return maxNum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << MinNum(n) << " " << MaxNum(n) << "\n";
	}

	return 0;
}