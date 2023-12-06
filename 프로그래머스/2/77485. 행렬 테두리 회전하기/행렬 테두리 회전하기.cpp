#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> answer;

void Rotate(int x1, int y1, int x2, int y2, int r, int c)
{
    int minNum = 2147000000;
    vector<vector<int>> temp(r, vector<int>(c));
    temp = v;
    for (int i = y1 + 1; i <= y2; i++) {
        temp[x1][i] = v[x1][i - 1];
        minNum = min(minNum, temp[x1][i]);
    }
    for (int i = x1 + 1; i <= x2; i++) {
        temp[i][y2] = v[i - 1][y2];
        minNum = min(minNum, temp[i][y2]);
    }
    for (int i = y2 - 1; i >= y1; i--) {
        temp[x2][i] = v[x2][i + 1];
        minNum = min(minNum, temp[x2][i]);
    }
    for (int i = x2 - 1; i >= x1; i--) {
        temp[i][y1] = v[i + 1][y1];
        minNum = min(minNum, temp[i][y1]);
    }
    v = temp;
    answer.push_back(minNum);
}

vector<int> solution(int r, int c, vector<vector<int>> qu) {
    v.resize(r, vector<int>(c));
    int a = 1;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            v[i][j] = a++;

    int n = qu.size();
    for (int i = 0; i < n; i++)
    {
        int x1 = qu[i][0] - 1;
        int y1 = qu[i][1] - 1;
        int x2 = qu[i][2] - 1;
        int y2 = qu[i][3] - 1;

        Rotate(x1, y1, x2, y2, r, c);
    }
    
    return answer;
}