#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> result;
int ch[9];

void BackT(int cnt)
{
	if(cnt == m){
		for(int i = 0; i < m; i++){
			cout << result[i] << " ";
		}
		cout << "\n";

		return;
	}

	for(int i = 0; i < n; i++)
	{
		if (ch[i] == 0){
			ch[i] = 1;
			result[cnt] = v[i];
			BackT(cnt + 1);
			ch[i] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	v.resize(n);
	result.resize(m);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	BackT(0);

	return 0;
}