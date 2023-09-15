#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int maxCnt;
int ch[8];

void DFS(int x, vector<vector<int>>& dungeons, int cnt)
{    
    if (cnt > maxCnt) {
        maxCnt = cnt;
    }

    for (int i = 0; i < dungeons.size(); i++) {
        if (ch[i] == 0 && x >= dungeons[i][0]) {
            ch[i] = 1;
            DFS(x - dungeons[i][1], dungeons, cnt + 1);
            ch[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    DFS(k, dungeons, 0);

    int answer = maxCnt;

    return answer;
}