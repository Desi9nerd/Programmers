#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int answer = 2147000000;
vector<vector<int>> v;
vector<pair<int, int>> house, chicken, delevery;
int ch[14]; // 치킨집 체크

int Distance()
{
	int sum = 0;
	for(int i=0; i<house.size(); i++)
	{
		int y = house[i].first;
		int x = house[i].second;
		int d = 2147000000;

		for (int j = 0; j < delevery.size(); j++)
		{
			int ny = delevery[j].first;
			int nx = delevery[j].second;
			int dist = abs(ny - y) + abs(nx - x);

			d = min(d, dist);
		}
		sum = sum + d;
	}

	return sum;
}

void Delivery(int idx, int cnt)
{
	if(cnt == m){
		answer = min(answer, Distance());
		return;
	}

	for(int i=idx; i<chicken.size(); i++)
	{
		if (ch[i] == 0)
		{
			delevery.push_back(chicken[i]);

			ch[i] = 1;
			Delivery(i, cnt + 1);
			ch[i] = 0;

			delevery.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	v.resize(n, vector<int>(n));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> v[y][x];

			if (v[y][x] == 1) {
				house.push_back({ y, x });
			}
			else if (v[y][x] == 2) {
				chicken.push_back({ y, x });
			}
		}
	}
	
	Delivery(0, 0);

	cout << answer << "\n";

	return 0;
}