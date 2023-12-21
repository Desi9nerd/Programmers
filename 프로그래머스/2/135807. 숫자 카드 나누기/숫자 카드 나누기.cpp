#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if (b == 0) 
        return a;

    return gcd(b, a % b);
}

int solution(vector<int> arrA, vector<int> arrB) {
    
    int x = arrA[0];
    for(int i = 1; i < arrA.size(); i++){
        x = gcd(x, arrA[i]);
    }

    int y = arrB[0];
    for (int i = 1; i < arrB.size(); i++) {
        y = gcd(y, arrB[i]);
    }

    bool useX = true;
    bool useY = true;
    if (x == 1 && y == 1) return 0;
    else if (x > 1 && y == 1)
    {
        for (int i = 0; i < arrB.size(); i++)
        {
            if (arrB[i] % x == 0) return 0;
        }
        return x;
    }
    else if (x == 1 && y > 1)
    {
        for (int i = 0; i < arrA.size(); i++)
        {
            if (arrA[i] % y == 0) return 0;
        }
        return y;
    }
    else if (x > 1 && y > 1)
    {
        for (int i = 0; i < arrB.size(); i++)
        {
            if (arrB[i] % x == 0){
                useX = false;
                break;
            };
        }
        for (int i = 0; i < arrA.size(); i++)
        {
            if (arrA[i] % y == 0){
                useY = false;
                break;
            }
        }

        if (useX == false && useY == false) return 0;
        else if (useX && useY == false) return x;
        else if (useX == false && useY) return y;
        else return x > y ? x : y;
    }
}