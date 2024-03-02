#include <iostream>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

	for(int a = 0; a * k <= d; a++)
	{
		// yy = x좌표가 a * k일 때 범위 내에 가질 수 있는 y좌표의 최대값
		long long yy = sqrt((long long)d * d - pow(a * k, 2));

		answer += (yy / k + 1);
	}

	return answer;
}