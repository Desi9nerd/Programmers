#include<iostream>
using namespace std;

int main() {
	int k=0;
	int s[26];
	for(int i=0; i<26; i++){
		s[i]=-1;
	}
	
	while(cin){
		char x;			
		cin>>x;
		
		if(s[x-'a']==-1)	
			s[x-'a']=k;
		k++;	
	}
	
	for(int i=0; i<26; i++){
		cout<<s[i]<<" ";
	}
	
	return 0;
}