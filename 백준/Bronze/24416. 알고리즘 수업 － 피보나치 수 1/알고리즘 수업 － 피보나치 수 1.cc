#include<iostream>
using namespace std;

int save[41], f[41];
int n, cnt1, cnt2;

int fib(int x)
{
	
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (save[x] != 0) return save[x];
	else cnt1++;
	
	return save[x] = fib(x-1) + fib(x-2);
}

int fibonacci(int a)
{
	f[1]=1;
	f[2]=1;
	for(int i=3; i<=n; i++){
		cnt2++;
		f[i]=f[i-1]+f[i-2];
	}
	return f[a];
}

int main() {
	scanf("%d", &n);
	
	fib(n);
	fibonacci(n);
	
	//printf("%d %d\n", cnt1, fibonacci(n));	
	printf("%d %d", save[n], cnt1);
}