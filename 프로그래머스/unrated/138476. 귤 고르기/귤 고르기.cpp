#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool Compare(pair<int,int>& a, pair<int,int>& b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> myMap;

    for (const auto& i : tangerine)
        myMap[i] = 0;

    for (const auto& i : tangerine)
        myMap[i]++;

    vector<pair<int, int>> v;
    for (auto it = myMap.begin(); it != myMap.end(); it++)
        v.push_back({it->first, it->second});

    sort(v.begin(), v.end(), Compare);

    for(int i=0; i<v.size(); i++)
    {
        if (k > 0) {
            k -= v[i].second;
            v[i].second = 0;
        }
        else
            break;
    }

    for(int i=0; i<v.size(); i++)
    {
        if (v[i].second == 0)
            answer++;
    }

    return answer;
}