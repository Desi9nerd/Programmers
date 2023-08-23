#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    map<string, bool> myMap;

    string input1, input2;
    for(int i=0; i<n; i++){
        cin >> input1 >> input2;
        
        if(input1 == "ChongChong" || input2 == "ChongChong"){
            myMap.insert({ input1, true });
            myMap.insert({ input2, true });
        }

        if (myMap.find(input1) != myMap.end())
            myMap.insert({ input2, true });

        if (myMap.find(input2) != myMap.end())
            myMap.insert({ input1, true });
    }

    cout << myMap.size();

    return 0;
}