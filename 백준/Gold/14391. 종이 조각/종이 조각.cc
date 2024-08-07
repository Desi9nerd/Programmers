#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int answer = 0;
vector<vector<int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n, vector<int>(m));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            char c;
            cin >> c;
            v[y][x] = c - '0'; // 문자를 숫자로 변환
        }
    }

    // 총 2^(n*m) 경우의 수를 비트마스크로 표현
    for (unsigned int bitmask = 0; bitmask < (1 << (n * m)); bitmask++) 
    {
        int totalSum = 0;

        // 가로 합 계산
        for (int y = 0; y < n; y++) 
        {
            int rowSum = 0;

            for (int x = 0; x < m; x++) 
            {
                int idx = y * m + x;

                if (bitmask & (1 << idx)) { // 가로로 합산
                    rowSum = rowSum * 10 + v[y][x];
                }
                else {
                    totalSum += rowSum;
                    rowSum = 0;
                }
            }

            totalSum += rowSum; // 마지막에 남은 숫자 추가
        }

        // 세로 합 계산
        for (int x = 0; x < m; x++) 
        {
            int colSum = 0;

            for (int y = 0; y < n; y++) 
            {
                int idx = y * m + x;

            	if ((bitmask & (1 << idx)) == 0) { // 세로로 합산
                    colSum = colSum * 10 + v[y][x];
                }
                else {
                    totalSum += colSum;
                    colSum = 0;
                }
            }

            totalSum += colSum; // 마지막에 남은 숫자 추가
        }

        answer = max(answer, totalSum);
    }

    cout << answer << '\n';

    return 0;
}