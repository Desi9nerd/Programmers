#include <iostream>
using namespace std;

int a, b, c;

long long mod_pow(long long base, long long exponent, long long mod)
{
   //지수=0인 경우
   if (exponent == 0) return 1;

   //지수가 홀수
   else if (exponent % 2 == 1) {
      return (base * mod_pow(base, exponent - 1, mod)) % mod;
   }
   //지수가 짝수
   else {
      long long temp = mod_pow(base, exponent / 2, mod);
      return (temp * temp) % mod;
   }

}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> a >> b >> c;

   cout << mod_pow(a, b, c);

   return 0;
}