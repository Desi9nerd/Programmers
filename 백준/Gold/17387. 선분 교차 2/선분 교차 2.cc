#include <iostream>
using namespace std;

using int64 = long long;

struct Point
{
	bool operator<(const Point& other) const { return x < other.x || (x == other.x && y < other.y); }
	bool operator>(const Point& other) const { return other < *this; }
	bool operator<=(const Point& other) const { return !(other < *this); }
	bool operator>=(const Point& other) const { return !(*this < other); }
	int64 x;
	int64 y;
};

int CCW(Point a, Point b, Point c)
{
	int64 ret = (a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
	if (ret > 0) return 1;
	if (ret < 0) return -1;
	return 0;
}

int main()
{
	Point A, B, C, D;
	cin >> A.x >> A.y >> B.x >> B.y;
	cin >> C.x >> C.y >> D.x >> D.y;

	int abc = CCW(A, B, C);
	int abd = CCW(A, B, D);
	int cda = CCW(C, D, A);
	int cdb = CCW(C, D, B);

	if (abc * abd == 0 && cda * cdb == 0)
	{
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);
		cout << (A <= D && C <= B);
		return 0;
	}

	cout << (abc * abd <= 0 && cda * cdb <= 0);
}
