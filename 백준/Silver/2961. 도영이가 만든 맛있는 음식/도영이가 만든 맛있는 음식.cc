#include <iostream>
#include <vector>
using namespace std;

int n;
long long answer = 987654321;
vector<pair<int, int>> taste;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	taste.resize(n);
	for (int i = 0; i < n; i++){
		cin >> taste[i].first >> taste[i].second;
	}

	for (int bitmask = 1; bitmask < (1 << taste.size()); bitmask++)
	{
		long long sour = 1, bitter = 0;

		for (int i = 0; i < taste.size(); i++)
		{
			if (bitmask & (1 << i)){
				sour *= taste[i].first;
				bitter += taste[i].second;
				//cout << "-- " << taste[i].first << ", " << taste[i].second << "\n";
			}
		}

		//cout << sour << ", " << bitter << "\n\n";
		answer = min(answer, abs(sour - bitter));
	}


	cout << answer << "\n";

	return 0;
}