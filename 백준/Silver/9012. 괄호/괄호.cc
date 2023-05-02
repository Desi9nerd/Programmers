#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
	cin.ignore(); 

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        char ch[51];
        int cnt = 0;
        strcpy(ch, s.c_str());

        for (int i = 0; i < strlen(ch); i++)
        {
            if (ch[i] == '(') cnt++;
            else if (ch[i] == ')') cnt--;

            if (cnt < 0) break;
        }
        if (cnt == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

