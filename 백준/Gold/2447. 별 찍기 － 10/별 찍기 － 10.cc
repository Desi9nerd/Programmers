#include <iostream>
using namespace std;

void Star(int y, int x, int num) 
{
    if ((y / num) % 3 == 1 && (x / num) % 3 == 1) 
        cout << ' ';
    
    else 
    {
        if (num / 3 == 0) 
            cout << '*';
        
        else 
            Star(y, x, num / 3);        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int y = 0; y < n; y++) 
    {
        for (int x = 0; x < n; x++) 
        {
            Star(y, x, n);
        }
        cout << '\n';
    }

    return 0;
}