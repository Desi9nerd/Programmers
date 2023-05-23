#include<stdio.h>
#include<deque>
using namespace std;

deque<int> dq;

int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		dq.push_back(i);
	}

	while(dq.size()>1)
	{
		dq.pop_front();
		
		int temp=dq.front();
		dq.pop_front();		
		dq.push_back(temp);		
	}
	
	printf("%d", dq.front());
	
	return 0;
}