#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
string input;
vector<vector<int>> v;

bool Check(int y, int x, int size)
{
    int firstValue = v[y][x];

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++)
        {
            if (v[i][j] != firstValue) return false;
        }
    }

	return true;
}

void Quad(int y, int x, int size)
{
	if (Check(y, x, size))
		cout << v[y][x];

	else 
	{
		int newSize = size / 2;

		cout << "(";

        Quad(y, x, newSize);
        Quad(y, x + newSize, newSize);
        Quad(y + newSize, x, newSize);
        Quad(y + newSize, x + newSize, newSize);

        cout << ")";
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        cin >> input;

        for (int j = 0; j < n; j++) {
            v[i][j] = input[j] - '0';
        }
    }

    Quad(0, 0, n);

    return 0;
}