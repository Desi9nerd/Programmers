#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, sum = 0;
    cin >> a >> b;

    map<int, bool> m;

    for (int i = 0; i < a + b; i++) {
        int tmp;
	    cin >> tmp;

	if (m[tmp] == true)
		m.erase(tmp);
	else
		m[tmp] = true;
	}

    cout << m.size();
}