#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m; // n: 사람의 수, m: 파티의 수
int k; // k: 진실을 아는 사람의 수
set<int> truth; // 진실을 아는 사람들을 담는 배열
int nVisiters; // nVisiters: 파티에 오는 사람의 수
vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cin >> k;
	int input;
	for (int i = 0; i < k; i++) {
		cin >> input;
		truth.insert(input);
	}

	v.resize(m);

	for (int t = 0; t < m; t++) // 파티 수 만큼 시행
	{
		cin >> nVisiters;
		vector<int> visiter(nVisiters); // 파티에 오는 사람들을 담는 배열
		for (int i = 0; i < nVisiters; i++) {
			cin >> visiter[i];
			v[t].push_back(visiter[i]);
		}
	}

	while (true) {
		bool updated = false;
		for (int t = 0; t < m; t++) {
			bool knowTruth = false;
			for (int i = 0; i < v[t].size(); i++) {
				if (truth.find(v[t][i]) != truth.end()) {
					knowTruth = true;
					break;
				}
			}
			if (knowTruth) {
				for (int i = 0; i < v[t].size(); i++) {
					if (truth.insert(v[t][i]).second) {
						updated = true;
					}
				}
			}
		}
		if (!updated) {
			break;
		}
	}

	int answer = m;
	for (int t = 0; t < m; t++) // 파티 수 만큼 시행
	{
		for(int i = 0; i < v[t].size(); i++)
		{
			if(truth.find(v[t][i]) != truth.end())
			{
				answer--; // 전체 파티수에서 진실만을 얘기해야 되는 파티 수를 뺌
				break;
			}
		}
	}

	cout << answer;
	return 0;
}
