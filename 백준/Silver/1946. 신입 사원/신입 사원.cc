#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n; // t: 테스트 케이스 개수, n: 지원자 수
int answer; // 선발할 수 있는 신입사원의 최대 인원수

struct Stat
{
	int doc;
	int interview;

	Stat(int a=0, int b=0) {
		doc = a;
		interview = b;
	}
	
	bool operator<(const Stat& a) const {
		return doc < a.doc;
	}
};

vector<Stat> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while(t--)
	{
		cin >> n;
		v.resize(n);
		for(int i = 0; i < n; i++){
			cin >> v[i].doc >> v[i].interview;
		}
		sort(v.begin(), v.end());

		answer = 1; // 첫 사람은 서류순위가 가장 낮으므로 무조건 등록
		int minInterviewRank = v[0].interview; // 첫 사람의 인터뷰순위

		for (int i = 0; i < n; i++) 
		{
            if (v[i].interview < minInterviewRank){
				answer++;
				minInterviewRank = v[i].interview;				
			}
		}

		cout << answer << "\n";
		v.clear();
	}

	return 0;
}