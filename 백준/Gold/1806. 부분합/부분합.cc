#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s; // n: 수열의 길이, s: 수열의 부분합 최소값
vector<int> result;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;
	vector<int> v(n);
	int front = 0;
	int sumNum = 0;
	for(int i=0; i<n; i++){
		cin >> v[i];

		sumNum += v[i];

		while (sumNum >= s)
		{
			result.push_back(i - front + 1);
			sumNum -= v[front];
			front++;
		}		
	}

	if (result.size() == 0)
		cout << "0\n";
	else {
		sort(result.begin(), result.end());
		cout << result[0] << "\n";
	}
	
	return 0;
}