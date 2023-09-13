#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size()));

    for (int y = 0; y < arr1.size(); y++) {
        for (int x = 0; x < arr2[0].size(); x++) {
            for (int k = 0; k < arr2.size(); k++)
            {
                answer[y][x] += arr1[y][k] * arr2[k][x];
            }
        }
    }
    
    return answer;
}