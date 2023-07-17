#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string input;
    cin >> input;

    int num = 0;
    bool minusFlag = false;
    int result = 0;

    for (char c : input) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        }
        else {
            if (minusFlag) 
            {
                result -= num;
            }
            else 
            {
                result += num;
            }
            num = 0;

            if (c == '-') minusFlag = true;
        }
    }

    if (minusFlag)
        result -= num;
   
    else 
        result += num;

    cout << result << endl;

    return 0;
}
