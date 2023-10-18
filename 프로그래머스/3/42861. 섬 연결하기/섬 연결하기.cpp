#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int city[101];

int Find(int x)
{
    if (x == city[x]) return x;

    return city[x] = Find(city[x]);
}

bool Compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for (int i = 0; i < n; i++){
        city[i] = i;
    }

    sort(costs.begin(), costs.end(), Compare);

    for (int i = 0; i < costs.size(); i++)
    {
        int start = Find(costs[i][0]);
        int end = Find(costs[i][1]);

        if (start != end){
            answer += costs[i][2];            
            city[end] = start; // Union 과정
        }
    }

    return answer;
}