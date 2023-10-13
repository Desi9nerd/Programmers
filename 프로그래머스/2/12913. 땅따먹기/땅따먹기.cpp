#include <vector>
using namespace std;

vector<vector<int>> dp;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    dp.resize(land.size(), vector<int>(4));

    for(int x=0; x<4; x++){
        dp[0][x] = land[0][x];
    }

    int tmpMax = 0;
    for(int y=1; y<land.size(); y++){
	    for(int x=0; x<4; x++)
	    {
            for(int k=0; k<4; k++)
            {
                if (x == k) continue;

                dp[y][x] = max(dp[y][x], dp[y - 1][k] + land[y][x]);
            }

            // 마지막 행의 dp[][]값들 중에서 최대값을 answer에 담기
            if (y == land.size() - 1) {
                if (answer < dp[y][x])
                    answer = dp[y][x];
            }
	    }        
    }
        
    return answer;
}