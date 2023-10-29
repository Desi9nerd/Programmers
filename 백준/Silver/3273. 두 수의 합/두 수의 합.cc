#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
vector<int> a;
int answer;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	a.resize(n);
	for(int i = 0; i< n; i++){
		cin >> a[i];
	}
	cin >> x;

	sort(a.begin(), a.end());

	int left = 0, right = n - 1;
	while (left < right)
	{
		if (a[left] + a[right] == x){
			answer++;
			left++;
		}
		else if (a[left] + a[right] < x){
			left++;
		}
		else if (a[left] + a[right] > x){
			right--;
		}
	}

	cout << answer;

	return 0;
}