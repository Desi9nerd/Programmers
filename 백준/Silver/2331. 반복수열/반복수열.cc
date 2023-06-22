#include <iostream>
#include <cmath>
using namespace std;

int a, p, digit, nextNum, i=0, cnt=0, result;
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
		//cout << "a: " << a;

		while (a > 0)
		{
			digit = a % 10;
			nextNum += pow(digit, p);

			a /= 10;
		}
		//cout << "  nextNum: " << nextNum << "\n";
		box[++i] = nextNum;
		a = nextNum;

		for(int k=0; k<cnt; k++)
		{
			if (nextNum == box[k])
			{
				result = k;

				goto exitLoop;
			}
			
		}
	}

	exitLoop:

	//for (int i = 0; i < 10; i++)
	//	cout << box[i] << "\n";


	cout << result;

	return 0;
}