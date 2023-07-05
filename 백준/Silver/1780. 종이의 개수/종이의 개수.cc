#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n, MinusCnt=0, ZeroCnt=0, OneCnt=0;
vector<vector<int>> v;

bool Check(int y, int x, int size)
{
    int firstValue = v[y][x];

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (v[i][j] != firstValue) return false;
        }
    }

    return true;
}

void Cut(int y, int x, int size)
{
    if (Check(y, x, size))
    {
        if (v[y][x] == -1)
            MinusCnt++;
        else if(v[y][x] == 0)
            ZeroCnt++;
        else if (v[y][x] == 1)
            OneCnt++;

    }
    else
    {
        int newSize = size / 3;

        Cut(y, x, newSize);
        Cut(y, x + newSize, newSize);
        Cut(y, x + newSize * 2, newSize);
        Cut(y + newSize, x, newSize);
        Cut(y + newSize, x + newSize, newSize);
        Cut(y + newSize, x + newSize * 2, newSize);
        Cut(y + newSize * 2, x, newSize);
        Cut(y + newSize * 2, x + newSize, newSize);
        Cut(y + newSize * 2, x + newSize * 2, newSize);
    }
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    Cut(0, 0, n);

    cout << MinusCnt << "\n";
    cout << ZeroCnt << "\n";
    cout << OneCnt << "\n";


    return 0;
}