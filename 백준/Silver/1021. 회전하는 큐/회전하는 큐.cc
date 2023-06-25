#include <iostream>
#include <deque>
using namespace std;

int n, m, input, cnt=0;
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for(int i=0; i<m; i++){
		cin >> input;

		int idx;
		for(int j=0; j<dq.size(); j++)
		{
			if(dq[j]==input)
			{
				idx = j;
				break;
			}
		}

		int left = idx;
		int right = dq.size() - idx - 1;
		if(left <=right)
		{
			while (dq.front() != input)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
		}
		else
		{
			while(dq.front() != input)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}

		dq.pop_front();
	}

	cout << cnt << "\n";
	
	return 0;
}