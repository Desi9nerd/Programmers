#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int answer;
vector<vector<int>> ch;

void BFS(int start, int n, vector<vector<int>> com)
{
    queue<int> Q;
    Q.push(start);

    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();
        ch[curr][curr] = 1;

        for (int i = 0; i < n; i++)
        {
            if (ch[curr][i] == 0 && com[curr][i] == 1) {
                ch[curr][i] = 1;
                ch[i][curr] = 1;
                Q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    ch.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        if (ch[i][i] == 0) {
            BFS(i, n, computers);
            answer++;
        }
    }

    return answer;
}