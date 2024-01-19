#include <iostream>
#include <vector>
#include <iomanip> // 소수점 자리 설정을 위한 헤더. setprecision() 사용가능
using namespace std;

struct Coor{
	double x; double y;
};

int n;
vector<Coor> v;

double Area(int idx)
{
	double x1 = v[idx].x;
	double y1 = v[idx].y;
	double x2 = v[idx+1].x;
	double y2 = v[idx+1].y;

	return (y1 - y2) * (x1 + x2) / 2; // 시계방향 기준 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v.resize(n+1);
	for(int i = 0; i < n; i++){
		cin >> v[i].x >> v[i].y;
	}

	v[n].x = v[0].x;
	v[n].y = v[0].y;

	double answer = 0.0f;
	for(int i = 0; i < n; i++)
	{
		answer += Area(i);
	}

	cout << fixed << setprecision(1) << abs(answer);

	return 0;
}