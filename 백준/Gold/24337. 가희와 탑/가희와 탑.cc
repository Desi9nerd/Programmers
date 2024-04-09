#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // 전체 건물의 개수
int a, b; // 가희, 단비 각각 볼 수 있는 건물의 개수

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> a >> b;

	vector<int> v1, v2;

	int tallest = max(a, b); // 가장 높은 빌딩의 높이

	// 가희(왼쪽) 기준 빌딩 배치
	for(int i = 1; i <= a; i++){
		if (i == a)
			v1.push_back(tallest);
		else
			v1.push_back(i);
	}

	// 단비(오른쪽) 기준 빌딩 배치
	for(int i = b - 1; i >= 1; i--){
		v2.push_back(i);
	}

	// 가희와 단비 기준으로 만족하는 빌딩 배치 시 필요한 건물이 전체 건물의 개수 보다 더 많은 경우 
	if (v1.size() + v2.size() > n) {
		cout << "-1";
		return 0;
	}

	// 만족하는 빌딩 배치 조건 외 추가로 들어갈 건물 수 구하기
	int additional = n - (v1.size() + v2.size());

	if (additional == 0){ // 추가로 들어갈 건물이 없다면
		for(int i = 0; i < v1.size(); i++)
			cout << v1[i] << " ";
		for (int i = 0; i < v2.size(); i++) 
			cout << v2[i] << " ";
	}
	else{ // 추가로 들어갈 건물이 있다면
		if(a <= 1){
			for (int i = 0; i < v1.size(); i++)
				cout << v1[i] << " ";
			for (int i = 0; i < additional; i++)
				cout << "1 ";
			for (int i = 0; i < v2.size(); i++)
				cout << v2[i] << " ";			
		}
		else{
			for (int i = 0; i < additional; i++)
				cout << "1 ";
			for (int i = 0; i < v1.size(); i++)
				cout << v1[i] << " ";
			for (int i = 0; i < v2.size(); i++)
				cout << v2[i] << " ";			
		}
	}

	return 0;
}