#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string str;
    cin >> str;
    int count = 0;
    set<string> substrings;

    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 0; j < str.size() - i; j++)
        {
            string tmp = str.substr(j, 1 + i);
            substrings.insert(tmp);
        }
    }

    count = substrings.size();

    cout << count;
    return 0;
}
