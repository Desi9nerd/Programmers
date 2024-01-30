#include <iostream>
using namespace std;

#define x first
#define y second
using Point = pair<long long, long long>;

int CCW(const Point& a, const Point& b, const Point& c)
{
	// 행렬식을 사용해서 외적 구하기
	long long result = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);

	if (result > 0) return 1;		 // CCW. 반시계 방향
	else if (result == 0) return 0; // 일직선
	else return -1;					 // CW. 시계 방향
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Point a, b, c, d;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;

	// CCW 구하기
	int ABC = CCW(a, b, c);
	int ABD = CCW(a, b, d);
	int CDA = CCW(c, d, a);
	int CDB = CCW(c, d, b);

	if (ABC * ABD == 0 && CDA * CDB == 0)
	{
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);

		if (a <= d && c <= b) cout << 1;
		else cout << 0;

		return 0;
	}

	if (ABC * ABD <= 0 && CDA * CDB <= 0) cout << 1;
	else cout << 0;

	return 0;
}
