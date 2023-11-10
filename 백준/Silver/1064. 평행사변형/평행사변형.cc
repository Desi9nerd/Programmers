#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;

	double d1;
	double d2;
	double d3;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	d1 = hypot(x2 - x3, y2 - y3);
	d2 = hypot(x3 - x1, y3 - y1);
	d3 = hypot(x1 - x2, y1 - y2);

	if ((x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1))
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << fixed;
		cout.precision(16);
		cout << (max(d1, max(d2, d3)) - min(d1, min(d2, d3))) * 2 << endl;
	}

	
	return 0;
}