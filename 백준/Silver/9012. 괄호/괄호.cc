#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
	cin.ignore(); 

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        
        int cnt = 0;
        

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(') cnt++;
            else if (s[i] == ')') cnt--;

            if (cnt < 0) break;
        }
        if (cnt == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}