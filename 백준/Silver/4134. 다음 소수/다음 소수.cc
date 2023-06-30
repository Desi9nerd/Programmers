#include <iostream>
using namespace std;

bool isPrime(long long x) 
{
    if (x <= 1) 
        return false;

    if (x == 2 || x == 3) 
        return true;

    if (x % 2 == 0 || x % 3 == 0)
        return false;

    for (long long i = 5; i * i <= x; ++i) 
    {
        if (x % i == 0 || x % (i + 2) == 0) 
            return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, num;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        while (!isPrime(num))
            num++;
        cout << num << endl;
    }
}