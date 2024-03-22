#include <string>
#include <vector>
using namespace std;

int solution(vector<string> b) {
    int answer = 1;

    int SumBingGo_O = 0;
    int SumBingGo_X = 0;

    int black = 0; // O
    int white = 0; // X

    vector<int> ColumnBingGo_O(3, 0);
    vector<int> ColumnBingGo_X(3, 0);

    for (int y = 0; y < 3; y++)
    {
        int RowBingGo_X = 0;
        int RowBingGo_O = 0;
        for (int x = 0; x < 3; x++)
        {
            if (b[y][x] == 'O') black++;
            else if (b[y][x] == 'X') white++;

            if (x < 2 && b[y][x] == b[y][x + 1] && b[y][x] == 'O') RowBingGo_O++;
            if (x < 2 && b[y][x] == b[y][x + 1] && b[y][x] == 'X') RowBingGo_X++;
            if (y < 2 && b[y][x] == b[y + 1][x] && b[y][x] == 'O') ColumnBingGo_O[x]++;
            if (y < 2 && b[y][x] == b[y + 1][x] && b[y][x] == 'X') ColumnBingGo_X[x]++;
        }

        if (RowBingGo_O == 2) SumBingGo_O++;
        if (RowBingGo_X == 2) SumBingGo_X++;
    }

    for (int i = 0; i < 3; i++) {
        if (ColumnBingGo_O[i] == 2) SumBingGo_O++;
        if (ColumnBingGo_X[i] == 2) SumBingGo_X++;
    }

    // 대각선 빙고
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[1][1] == 'O') SumBingGo_O++;
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[1][1] == 'O') SumBingGo_O++;
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[1][1] == 'X') SumBingGo_X++;
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[1][1] == 'X') SumBingGo_X++;

    // 후공인 X가 더 많은 경우, 선공인 O가 1개 초과 더 많은 경우
    if (black < white || black > white + 1) {
        return 0;
    }
        
    if (SumBingGo_O >= 1){
        if (SumBingGo_X >= 1) return 0;
        if (black <= white) return 0;
    }

    if (SumBingGo_X >= 1){
        if (SumBingGo_O >= 1) return 0;
        if (black != white) return 0;
    }
    
    return answer;
}