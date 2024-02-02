#include <vector>
#include <algorithm>
using namespace std;

int Col = 0;

bool Compare(const vector<int>& a, const vector<int>& b) {
    if (a[Col] == b[Col])
        return a[0] > b[0];

    return a[Col] < b[Col];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    
    Col = col - 1; // 문제는 0이 아닌 1부터 시작이기 때문에 -1

	sort(data.begin(), data.end(), Compare); // 문제 조건에 맞게 정렬

    int answer = 0;
    for (int i = row_begin; i <= row_end; i++) 
    {
        int temp = 0;
        for (int j = 0; j < data[0].size(); j++) {
            temp += data[i - 1][j] % i; // mod 연산
        }
        answer = answer ^ temp; // XOR 연산
    }

    return answer;
}