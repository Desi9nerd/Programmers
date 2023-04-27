#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v;

int main() {
	int t, a, b, cf;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) 
	{
		cf = 1;
		scanf("%d %d", &a, &b);

		if(a>b)
		{
			for (int j = b; j >= 1; j--)
			{
				if (a % j == 0 && b % j == 0)
				{
					cf *= j; //공약수를 곱해 최대공약수를 구함. 
					a /= j;
					b /= j;
				}
			}
		}
		else
		{
			for (int j = a; j >= 1; j--)
			{
				if (a % j == 0 && b % j == 0)
				{
					cf *= j; //공약수를 곱해 최대공약수를 구함. 
					a /= j;
					b /= j;
				}
			}
		}

		v.push_back(a * b * cf);
	}

	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);

	return 0;
}

