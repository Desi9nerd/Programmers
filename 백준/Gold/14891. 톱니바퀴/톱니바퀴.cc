#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int k, input, rDir;
string inputNumber;
vector<int> v1, v2, v3, v4;

void Rotate(vector<int>& v, int dir)
{
	if (dir == -1)
	{
		rotate(v.begin(), v.begin() + 1, v.end());

		return;
	}
	else if (dir == 1)
	{
		rotate(v.begin(), v.end() - 1, v.end());

		return;
	}
	else
		return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	v1.resize(8);
	v2.resize(8);
	v3.resize(8);
	v4.resize(8);

	cin >> inputNumber;
	for (int i = 0; i < 8; i++) {
		v1[i] = inputNumber[i] - '0';
	}
	cin >> inputNumber;
	for (int i = 0; i < 8; i++) {
		v2[i] = inputNumber[i] - '0';
	}
	cin >> inputNumber;
	for (int i = 0; i < 8; i++) {
		v3[i] = inputNumber[i] - '0';
	}
	cin >> inputNumber;
	for (int i = 0; i < 8; i++) {
		v4[i] = inputNumber[i] - '0';
	}


	cin >> k;
	
	for (int i = 0; i < k; i++) {
		cin >> input;
		if (input == 1) {
			cin >> rDir;
			if (v1[2] != v2[6] && v2[2] != v3[6] && v3[2] != v4[6])
			{
				Rotate(v1, rDir);
				Rotate(v2, -rDir);
				Rotate(v3, rDir);
				Rotate(v4, -rDir);
			}
			else if (v1[2] != v2[6] && v2[2] != v3[6] && v3[2] == v4[6])
			{
				Rotate(v1, rDir);
				Rotate(v2, -rDir);
				Rotate(v3, rDir);
			}
			else if (v1[2] != v2[6] && v2[2] == v3[6])
			{
				Rotate(v1, rDir);
				Rotate(v2, -rDir);
			}
			else if (v1[2] == v2[6])
				Rotate(v1, rDir);
		}
		else if (input == 2) {
			cin >> rDir;
			if (v1[2] != v2[6] && v2[2] != v3[6] && v3[2] != v4[6]) 
			{
				Rotate(v1, -rDir);
				Rotate(v2, rDir);
				Rotate(v3, -rDir);
				Rotate(v4, rDir);
			}
			else if (v1[2] != v2[6] && v2[2] != v3[6] && v3[2] == v4[6])
			{
				Rotate(v1, -rDir);
				Rotate(v2, rDir);
				Rotate(v3, -rDir);
			}
			else if (v1[2] != v2[6] && v2[2] == v3[6])
			{
				Rotate(v1, -rDir);
				Rotate(v2, rDir);
			}
			else if (v1[2] == v2[6] && v2[2] != v3[6] && v3[2] != v4[6])
			{
				Rotate(v2, rDir);
				Rotate(v3, -rDir);
				Rotate(v4, rDir);
			}
			else if (v1[2] == v2[6] && v2[2] != v3[6] && v3[2] == v4[6])
			{
				Rotate(v2, rDir);
				Rotate(v3, -rDir);
			}
			else if (v1[2] == v2[6] && v2[2] == v3[6])
			{
				Rotate(v2, rDir);
			}
		}
		else if (input == 3) {
			cin >> rDir;
			if (v1[2] != v2[6] && v2[2] != v3[6] && v3[2] != v4[6])
			{
				Rotate(v1, rDir);
				Rotate(v2, -rDir);
				Rotate(v3, rDir);
				Rotate(v4, -rDir);
			}
			else if (v1[2] == v2[6] && v2[2] != v3[6] && v3[2] != v4[6])
			{
				Rotate(v2, -rDir);
				Rotate(v3, rDir);
				Rotate(v4, -rDir);
			}
			else if (v1[2] != v2[6] && v2[2] != v3[6] && v3[2] == v4[6])
			{
				Rotate(v1, rDir);
				Rotate(v2, -rDir);
				Rotate(v3, rDir);
			}
			else if (v1[2] == v2[6] && v2[2] != v3[6] && v3[2] == v4[6])
			{
				Rotate(v2, -rDir);
				Rotate(v3, rDir);
			}
			else if (v2[2] == v3[6] && v3[2] != v4[6])
			{
				Rotate(v3, rDir);
				Rotate(v4, -rDir);
			}
			else if (v2[2] == v3[6] && v3[2] == v4[6])
			{
				Rotate(v3, rDir);
			}
		}
		else if (input == 4) {
			cin >> rDir;
			if (v3[2] != v4[6] && v2[2] != v3[6] && v1[2] != v2[6])
			{
				Rotate(v4, rDir);
				Rotate(v3, -rDir);
				Rotate(v2, rDir);
				Rotate(v1, -rDir);
			}
			else if (v3[2] != v4[6] && v2[2] != v3[6] && v1[2] == v2[6])
			{
				Rotate(v4, rDir);
				Rotate(v3, -rDir);
				Rotate(v2, rDir);
			}
			else if (v3[2] != v4[6] && v2[2] == v3[6])
			{
				Rotate(v4, rDir);
				Rotate(v3, -rDir);
			}
			else if (v3[2] == v4[6])
				Rotate(v4, rDir);
		}
	}
	
	
	cout << v1[0] + v2[0] * 2 + v3[0] * 4 + v4[0] * 8;

	return 0;
}