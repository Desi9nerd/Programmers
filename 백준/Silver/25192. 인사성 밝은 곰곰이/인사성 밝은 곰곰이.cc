#include<iostream>
#include<string>
#include<set>
using namespace std;	

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, cnt=0;
	cin>>n;
	
	string input;
	set<string> s;
		
	for(int i=0; i<n; i++){
		cin>>input;
		
		if(input=="ENTER")
		{
			s.clear();
		}
		else
		{
			set<string>::iterator it = s.find(input);
			if(it !=s.end()) continue;
			else
			{
				s.insert(input);
				cnt++;
			}
		}
	}

	cout<<cnt;
	
	return 0;
}
