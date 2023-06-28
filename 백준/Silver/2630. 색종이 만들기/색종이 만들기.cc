#include <iostream>
#include <vector>
using namespace std;

int n, blue = 0, white=0;
vector<vector<int>> v;

int Check(int y1, int y2, int x1, int x2)
{
    int color = v[y1][x1];
    for (int i = y1; i < y2; i++) {
        for (int j = x1; j < x2; j++) {
            if (v[i][j] != color) return 0;
        }
    }

    return 1;
}

void Select(int y1, int y2, int x1, int x2)
{
    if (Check(y1, y2, x1, x2) > 0) 
    {
        if (v[y1][x1] == 0) white++;
        else blue++;

        return;
    }

    int midY = (y1 + y2) / 2;
    int midX = (x1 + x2) / 2;

    Select(y1, midY, x1, midX);
    Select(y1, midY, midX, x2);
    Select(midY, y2, x1, midX);
    Select(midY, y2, midX, x2);
}

int main()
{
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

    Select(0, n, 0, n);

    cout << white << "\n";
    cout << blue << "\n";

    return 0;
}