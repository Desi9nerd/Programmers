#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board){
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> dp(row, vector<int>(col));
    
    if (row == 1 && col == 1) {
        if (board[0][0] == 1) return 1;
        else return 0;
    }
    
    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            dp[y][x] = board[y][x];
        }
    }

    int answer = 0;
    for (int y = 0; y < row - 1; y++) {
        for (int x = 0; x < col - 1; x++) 
        {
            if (board[y+1][x+1] == 1)
            {
                dp[y + 1][x + 1] = 1 + min(dp[y][x], min(dp[y + 1][x], dp[y][x + 1]));

                answer = max(answer, dp[y + 1][x + 1]);
            }
        }
    }

    answer = answer * answer;

    return answer;
}
