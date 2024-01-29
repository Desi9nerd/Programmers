#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
int answer = -1;
bool flag = false;
int arr[10][10];

bool isSqureNum(int n) 
{
    int root = (int)sqrt(n);

    if (root * root == n) 
        return true;
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    string tmp = "";
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = (int)tmp[j - 1] - 48;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int x = -n; x < n; x++) { // 행의 등차 
                for (int y = -m; y < m; y++) // 열의 등차
                { 
                    if (x == 0 && y == 0) continue;

                    int a = i, b = j;
                    int now = 0;
                    while (a > 0 && a <= n && b > 0 && b <= m) 
                    {
                        now *= 10;
                        now += arr[a][b];
                        if (isSqureNum(now)) answer = max(answer, now);
                        a += x;
                        b += y;
                    }

                    if (isSqureNum(now)) answer = max(answer, now);
                }
            }
        }
    }
    cout << answer << endl;
}
