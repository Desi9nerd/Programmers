#include <iostream>
using namespace std;

long long GCD(long long x, long long y)
{
	return y ? GCD(y, x % y) : x;
}

long long solution(int w, int h) {

	if (w > h) swap(w, h);

	long long gcd = GCD(w, h);
	long long a = w / gcd;
	long long b = h / gcd;
	//cout << a << " : " << b << "\n";

	long long answer = (long long)w * (long long)h;
	if(a == 1){
		answer -= b * w;
	}
	else{
		answer -= (a + b - 1) * (h / b);
	}

    return answer;
}