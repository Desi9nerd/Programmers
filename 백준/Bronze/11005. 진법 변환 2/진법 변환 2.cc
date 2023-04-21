#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, b, temp;
	cin >> n >> b;
	vector<int> v;

	while (n > 0)
	{
		temp = n % b;
		v.push_back(temp);
		n /= b;
	}

	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] >= 0 && v[i] < 10)
		{
			cout << v[i];
		}
		else
		{
			cout << (char)(v[i] + 'A' - 10);
		}
	}

	return 0;
}