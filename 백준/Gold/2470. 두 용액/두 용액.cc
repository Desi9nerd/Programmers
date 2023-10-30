#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v; // 주어진 용액을 담는 배열
int resultSumSol = 2147000000;
int firstSol, secondSol;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n);
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int sumSol = v[left] + v[right];

		if (sumSol == 0){
			cout << v[left] << " " << v[right] << "\n";
			return 0;
		}
		
        if(abs(sumSol) < resultSumSol){
            resultSumSol = abs(sumSol);
            firstSol = v[left];
            secondSol = v[right];
        }

		if (sumSol > 0) {
			right--;
        } else {
			left++;
        }
    }

	cout << firstSol << " " << secondSol << "\n";
	
	return 0;
}
