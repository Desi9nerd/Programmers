#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> A, B;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	A.resize(n);
	B.resize(m);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	int p1 = 0, p2 = 0;
	while (true)
	{
		if (n <= p1 && m <= p2) break;

		if (m <= p2 || (p1 < n && A[p1] < B[p2])) {
			cout << A[p1] << " ";
			p1++;
		}
		else {
			cout << B[p2] << " ";
			p2++;
		}
	}


	return 0;
}