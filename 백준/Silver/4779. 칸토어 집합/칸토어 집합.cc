#include <iostream>
#include <cmath>
using namespace std;

void Cantor(int n) 
{
	int size = pow(3, n - 1);

	if (n == 0) { // N = 0 인 경우 "-" 출력
		cout << "-";
		return;
	}

	// N번째 칸토어 집합 = N -1 번째 칸토어 집합을 2개 이은 것
	// 사이에 공백이 N - 1번째 칸토어 집합의 사이즈만큼 있어야 함
	Cantor(n - 1);
	for (int i = 0; i < size; i++) {
		cout << " ";
	}
	Cantor(n - 1);
}

int main() {
	int n;

	while (cin >> n) {
		Cantor(n);
		cout << "\n";
	}

	return 0;
}