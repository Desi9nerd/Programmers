#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Value {
    int rowNum; int colVal; int firstVal;

    Value(int a, int b, int c) {
        rowNum = a;
        colVal = b;
        firstVal = c;
    }

    bool operator<(const Value& oper) const
    {
        if (colVal == oper.colVal) {
            return firstVal > oper.firstVal;
        }

        return colVal < oper.colVal;
    }
};

vector<Value> order; // 행, col번째 값, 첫번째 컴럼의 값

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
   
    int r = data.size();
    int c = data[0].size();
    
    for (int i = 0; i < r; i++) {
        order.push_back({ i, data[i][col-1], data[i][0] });
    }

    sort(order.begin(), order.end());


    int answer = 0;
    for (int i = row_begin; i <= row_end; i++) 
    {
        int temp = 0;
        for (int j = 0; j < c; j++) {
            temp += (data[order[i-1].rowNum][j] % i);
        }
        answer = answer ^= temp;
    }

    return answer;
}
