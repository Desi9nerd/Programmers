#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c; // n: 마을의 수, c: 트럭의 용량
int m;	  // m: 보내는 박스의 개수
int answer;

struct Info {
	int start, end, box;

	Info(int a, int b, int c) {
		start = a;
		end = b;
		box = c;
	}

	bool operator<(const Info& oper) {
		if (end == oper.end) {
			start < oper.start;
		}
		return end < oper.end;
	}
};

vector<Info> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> c >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a, b, c });
	}
	sort(v.begin(), v.end());

	vector<int> capacity(n + 1, c); // 각 마을별 남은 용량

	for (int i = 0; i < v.size(); i++)
	{
		int minCap = c;
		for (int j = v[i].start; j < v[i].end; j++) {
			minCap = min(minCap, capacity[j]);
		}

		int canLoad = min(minCap, v[i].box);
		for (int j = v[i].start; j < v[i].end; j++) {
			capacity[j] -= canLoad;
		}

		answer += canLoad;
	}

	cout << answer;

	return 0;
}
