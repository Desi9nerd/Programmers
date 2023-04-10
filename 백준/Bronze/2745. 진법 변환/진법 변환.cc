#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string N;
int B;
int result;
int cnt = 0;
 
 
int main(void) 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	cin >> N >> B;
 
	for (int i = N.length() - 1; i >= 0; i--) {
 
		if (N[i] >= 'A' && N[i] <= 'Z')
			result += (N[i] - 'A' + 10) * ((int)pow(B, cnt));
		else
			result += (N[i] - '0') * ((int)pow(B, cnt));
		cnt++;
	}
	cout << result << '\n';
 
	return 0;
}