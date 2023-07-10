#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> v;

int sum1, sum2, sum3, sum4, sum5, sum6, sum7, sum8, sum9, sum10;
int maxValue1, maxValue2, maxValue3, maxValue4, maxValue5, maxValue6, maxValue7, maxValue8, maxValue9, maxValue10, maxValue;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    v.resize(n+4, vector<int>(m+4));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> v[y][x];
        }
    }

    //주황색
    int dirY[6] = { 0, 0, 1, 1, 2, 2 };
    int dirX[6] = { -1, 1, -1, 1, -1, 1 };
    int dirYY[6] = { -1, 1, -1, 1, -1, 1 };
    int dirXX[6] = { 0, 0, 1, 1, 2, 2};
    
    //보라색
    int dirYYY[2] = { -1, 1 };
    int dirXXX[2] = { -1, 1 };
        
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            //하늘색
            sum1 = v[y][x] + v[y + 1][x] + v[y + 2][x] + v[y + 3][x];
            sum2 = v[y][x] + v[y][x + 1] + v[y][x + 2] + v[y][x + 3];

            if (maxValue1 < sum1) maxValue1 = sum1;
            if (maxValue2 < sum2) maxValue2 = sum2;

            //노란색
            sum3 = v[y][x] + v[y][x + 1] + v[y + 1][x] + v[y + 1][x + 1];
            if (maxValue3 < sum3) maxValue3 = sum3;

            //주황색
            for (int i = 0; i < 6; i++)
            {
                if (x < 1) {
                    if (i == 0 || i == 2 || i == 4) continue;
                    else
                        sum4 = v[y][x] + v[y + 1][x] + v[y + 2][x] + v[y + dirY[i]][x + dirX[i]];
                }
                else {
                    sum4 = v[y][x] + v[y + 1][x] + v[y + 2][x] + v[y + dirY[i]][x + dirX[i]];
                }

                if (maxValue4 < sum4) maxValue4 = sum4;
            }
            for (int i = 0; i < 6; i++)
            {
                if (y < 1) {
                    if (i == 0 || i == 2 || i == 4) continue;
                    else
                        sum5 = v[y][x] + v[y][x + 1] + v[y][x + 2] + v[y + dirYY[i]][x + dirXX[i]];
                }
                else {
                    sum5 = v[y][x] + v[y][x + 1] + v[y][x + 2] + v[y + dirYY[i]][x + dirXX[i]];
                }

                if (maxValue5 < sum5) maxValue5 = sum5;
            }


            //초록색
            sum6 = v[y + 1][x] + v[y + 1][x + 1] + v[y][x + 1] + v[y][x + 2];
            sum7 = v[y][x] + v[y][x + 1] + v[y + 1][x + 1] + v[y + 1][x + 2];

            sum8 = v[y][x] + v[y+1][x] + v[y+1][x+1] + v[y+2][x+1];
            sum9 = v[y][x + 1] + v[y + 1][x] + v[y + 1][x + 1] + v[y + 2][x];
            if (maxValue6 < sum6) maxValue6 = sum6;
            if (maxValue7 < sum7) maxValue7 = sum7;
            if (maxValue8 < sum8) maxValue8 = sum8;
            if (maxValue9 < sum9) maxValue9 = sum9;
        }

        maxValue = max(maxValue9, max(maxValue8, max(maxValue7, max(maxValue6, max(maxValue5, max(maxValue4, max(maxValue3, max(maxValue1, maxValue2))))))));
    }

    cout << maxValue;

    return 0;
}