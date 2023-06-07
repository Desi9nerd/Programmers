#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<string, string> mp;
    string name, inout;

    for (int i = 0; i < n; i++) {
        cin >> name >> inout;

        if (inout == "enter") {
            mp[name] = inout;
        }
        else if (inout == "leave") {
            mp.erase(name);
        }
    }

    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        cout << it->first << "\n";
    }

    return 0;
}