#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool Compare(vector<int>& v1, vector<int>& v2) {
    if (v1[1] < v2[1]) return true;
    if (v1[1] == v2[1] && v1[0] < v2[0]) return true;

    return false;
}

int solution(vector<vector<int>> routes) {
    int n = routes.size();

    sort(routes.begin(), routes.end(), Compare);
    
    int answer = 1;
    int curr = routes[0][1];
    int i = 1; // 두 번째부터 시작 

    while (i < n)
    {
        if (curr < routes[i][0]) {
            curr = routes[i][1];
            answer++;
        }

        i++;
    }


    return answer;
}
