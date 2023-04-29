#include <stdio.h>
using namespace std;

int GCD(int x, int y)
{
	return y ? GCD(y, x%y) : x;
}

int main() {
	int a, b, c, d, top, down, gcd;

	scanf("%d %d", &a, &b);
	scanf("%d %d", &c, &d);

	top = a * d + b * c;
	down = b * d;

	if(top>=down)
		gcd = GCD(top, down);
	else
		gcd = GCD(down, top);

	printf("%d %d\n", top/gcd, down/gcd);

	return 0;
}