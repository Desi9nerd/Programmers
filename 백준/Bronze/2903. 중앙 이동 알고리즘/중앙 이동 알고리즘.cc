#include <iostream>
using namespace std;
//ans = (1 + 2^n)^2
int main() {
    int n;
    cin >> n;
    int pow = 1;
    for (int i = 1; i <= n; i++)
        pow *= 2;
    cout << (1 + pow) * (1 + pow) << '\n';
}
