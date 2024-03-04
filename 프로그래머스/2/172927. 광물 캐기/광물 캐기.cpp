#include <string>
#include <vector>
using namespace std;

vector<vector<int>> consume = { {1, 1, 1}, {5, 1, 1}, {25, 5, 1} };

int DFS(int depth, int cnt, vector<int>& picks, vector<int>& m)
{
    if (depth >= m.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0))
        return cnt;

    int minCnt = INT32_MAX;
    int temp, j;
    for (int i = 0; i < 3; i++)
    {
        if (picks[i])
        {
            picks[i]--;
            temp = 0;
            j = depth;

            while (j < depth + 5 && j < m.size()) {
                temp += consume[i][m[j++]];
            }

            minCnt = min(minCnt, DFS(j, cnt + temp, picks, m));
            picks[i]++;
        }
    }

    return minCnt;
}

int solution(vector<int> picks, vector<string> minerals)
{
    vector<int> m;

    for (string& iter : minerals)
    {
        if (iter == "diamond")
            m.push_back(0);
        else if (iter == "iron")
            m.push_back(1);
        else
            m.push_back(2);
    }

    return DFS(0, 0, picks, m);
}