#include <iostream>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
 
	int N, X;
	cin >> N >> X;
 
	int val;
	for (int i = 0; i < N; i++) {
		cin >> val;
		if (val < X) {
			cout << val << " ";
		}
	}
 
	return 0;
}