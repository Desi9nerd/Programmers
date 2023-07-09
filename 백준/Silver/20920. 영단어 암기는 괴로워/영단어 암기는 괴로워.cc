#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool Comp(const pair<string, int>& a, const pair<string, int>& b)
{
    if (a.second == b.second)
    {
        if (a.first.length() == b.first.length())
            return a.first < b.first;
        return a.first.length() > b.first.length();
    }
    else
        return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<string, int> myMap;
    string input;

    for(int i = 0; i < n; i++){
        cin >> input;

        if(input.length() >= m)
        {
            if (myMap.find(input) != myMap.end())
                myMap[input]++;
            else
                myMap[input] = 1;
        }
    }

    vector<pair<string, int>> vec(myMap.begin(), myMap.end());
    sort(vec.begin(), vec.end(), Comp);

    for (const auto& i : vec)
        cout << i.first << "\n";

    return 0;
}
