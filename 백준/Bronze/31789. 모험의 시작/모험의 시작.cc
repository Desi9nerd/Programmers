#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int money, bossATK;
int possibleMaxATK;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> money >> bossATK;

	int price, weaponATK;
	for (int i = 0; i < n; i++) {
		cin >> price >> weaponATK;
		
		if (price <= money) {
			possibleMaxATK = max(possibleMaxATK, weaponATK);
		}
	}

	if (possibleMaxATK > bossATK) cout << "YES";
	else cout << "NO";

	return 0;
}