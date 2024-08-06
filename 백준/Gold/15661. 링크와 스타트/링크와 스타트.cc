#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int answer = 987654321;
vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n, vector<int>(n));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> v[y][x];
		}
	}

	
	for (unsigned int bitmask = 0; bitmask < (1 << n); bitmask++)
	{
		vector<int> teamStart, teamLink;

		// teamStart, teamLink 구하기
		for (int i = 0; i < n; i++)
		{
			if (bitmask & (1 << i)) {
				teamStart.push_back(i);
			}
			else {
				teamLink.push_back(i);
			}
		}
		sort(teamStart.begin(), teamStart.end());
		sort(teamLink.begin(), teamLink.end());

		
		// sum 값 구하기
		int sumStart = 0, sumLink = 0;
		for (int i = 0; i < teamStart.size(); i++){
			for (int j = 0; j < teamStart.size(); j++)
			{
				sumStart += v[teamStart[i]][teamStart[j]];
			}
		}

		for (int i = 0; i < teamLink.size(); i++) {
			for (int j = 0; j < teamLink.size(); j++)
			{
				sumLink += v[teamLink[i]][teamLink[j]];
			}
		}

		answer = min(answer, abs(sumStart - sumLink));
	}

	cout << answer;

	return 0;
}