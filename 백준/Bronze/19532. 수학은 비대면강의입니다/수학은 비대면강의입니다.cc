#include<iostream>
using namespace std;

int main() {
	int x, y, a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	
	x = (e*c - b*f) / (e*a - b*d);
	y = (d*c - a*f) / (d*b - a*e);
	
	printf("%d %d", x, y);	
}