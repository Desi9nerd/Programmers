#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v;
queue<int> Q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k, input, cnt=0;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		Q.push(i);
	}

	while(!Q.empty())
	{
		cnt++;

		if (cnt % k == 0) 
		{
			v.push_back(Q.front());
			Q.pop();
		}
		else 
		{
			int temp = Q.front();
			Q.pop();
			Q.push(temp);
		}
	}

	cout << "<" << v[0];
	for (int i = 1; i < v.size(); i++) {
		cout << ", " << v[i];
	}
	cout << ">";

	return 0;
}