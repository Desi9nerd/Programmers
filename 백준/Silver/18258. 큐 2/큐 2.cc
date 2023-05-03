#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<int> Q;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "push") {
            int num;
            cin >> num;
            Q.push(num);
        }
        else if (s == "pop") {
            if (Q.empty()) cout << "-1\n";
            else {
                cout << Q.front() << "\n";
            	Q.pop();
            }
        }
        else if (s == "size") cout << Q.size() << "\n";
        else if (s == "empty"){
            if (Q.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (s =="front") {
            if (Q.empty()) cout << "-1\n";
            else cout << Q.front() << "\n";
        }
        else if (s =="back"){
            if (Q.empty()) cout << "-1\n";
            else cout << Q.back() << "\n";
        }
    }
    return 0;
}