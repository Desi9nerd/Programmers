#include <bits/stdc++.h>
using namespace std;

stack<int> s;
int n, t, cnt=1;

int main(){	
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; 
	
	while(n--){
		cin >> t;
		
		if(t == cnt) cnt++; 
		else s.push(t); 
		
		while(!s.empty() && s.top()==cnt)
        {
			s.pop();  
			cnt++;
		}
	}
	
	if(s.empty()) cout << "Nice";  
	else cout << "Sad";
}