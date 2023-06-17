#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x, n, m, input, cnt;
	cin >> x;

	for(int i=0; i<x; i++){
		cin >> n >> m;

		//for문이 돌때마다 초기화 해줘야 하므로 여기다 Queue, PriorityQueue선언.  
		queue<pair<int, int>> Q;
		priority_queue<int> pQ;

		for(int j=0; j<n; j++){
			cin >> input;
			Q.push(make_pair(j, input));
			pQ.push(input);
		}

		cnt = 0;

		while(!Q.empty())
		{
			int idx = Q.front().first;
			int input = Q.front().second;
			Q.pop();

			if(pQ.top() == input)
			{
				pQ.pop();
				cnt++;

				if(idx == m)
				{
					cout << cnt << "\n";
					break;
				}
			}

			else Q.push(make_pair(idx, input));
		}
	}

	return 0;
}