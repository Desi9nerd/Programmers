#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int dp[500][500];

    dp[0][0] = triangle[0][0];
    dp[1][0] = dp[0][0] + triangle[1][0];
    dp[1][1] = dp[0][0] + triangle[1][1];

    for(int y = 2; y < triangle.size(); y++)
    {
	    for(int x = 0; x < triangle[y].size(); x++)
	    {
            if (x == 0)
                dp[y][x] = dp[y - 1][x] + triangle[y][x];

	    	else if (x == triangle[y].size())
                dp[y][x] = dp[y - 1][x - 1] + triangle[y][x];

            else
				dp[y][x] = max(dp[y - 1][x - 1], dp[y - 1][x]) + triangle[y][x];

            if (dp[y][x] > answer) answer = dp[y][x];
	    }
    }    

    return answer;
}