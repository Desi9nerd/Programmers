#include <stdio.h>

int GCD(int a, int b)
{
    return b ? GCD(b, a%b) : a;
}

int main()
{
    int T, A, B;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", A*B / GCD(A, B));
    }
}