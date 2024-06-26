#include <iostream>
using namespace std;
 
const int MOD = 1000000007;
long long n,k;
long long answer;
 
long long fact(long long start, long long end)
{
    long long ret = 1;
    
    for(int i = start; i <= end; i++){
        ret = ret * i % MOD;
    }
 
    return ret;
}
 
long long power(int a, int b)
{
    if(b == 1) return a % MOD;
    
    long long half = power(a,b/2);
    
    if(b%2==1){
        return half * half % MOD * a % MOD;
    }
    else{
        return half * half % MOD;
    }
}
 
 
int main(){
    cin >> n >> k;
    
    answer = fact(n-k+1, n) * power(fact(1, k), MOD-2) % MOD;
    
    cout << answer;
    return 0;
}