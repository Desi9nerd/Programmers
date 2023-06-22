#include <iostream>
#include <cmath>
using namespace std;

int a, p, nextNum, i=0, cnt=0;
int box[10000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> p;
	box[0] = a;
	

	while(true)
	{
		cnt++;
		nextNum = 0;

		while (a > 0)
		{
			nextNum += pow(a % 10, p);

			a /= 10;
		}
		box[++i] = nextNum;
		a = nextNum;

		for(int k=0; k<cnt; k++)
		{
			if (nextNum == box[k])
			{
				cout << k;

				return 0;
			}			
		}//for
	}

	return 0;
}