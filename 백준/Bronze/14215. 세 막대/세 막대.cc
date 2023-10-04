#include <iostream>
using namespace std;
int main()
{
    int arr[3]; bool flag[3] = { false };
    int max = 0; int idx; int sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        cin >> arr[i];
        if (arr[i] > max) { max = arr[i]; idx = i; }
    }
    
    flag[idx] = true;
    
    while (true)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (flag[i] == true) continue;
            else sum += arr[i];
        }
        
        if (arr[idx] < sum) break;
        
        sum = 0; --arr[idx];
    }
    cout << sum + arr[idx];
}