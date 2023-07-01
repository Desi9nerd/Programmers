#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> DQ;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	string input;
	cin >> n;

	for (int i=0; i<n; i++)
	{
		cin >> input;
		
		if(input=="push_front"){
			cin >> num;
			DQ.push_front(num);
		}
		else if (input == "push_back") {
			cin >> num;
			DQ.push_back(num);
		}
		else if (input == "pop_front") {
			if (DQ.empty()) cout << "-1" << "\n";
			else {
				cout << DQ.front() << "\n";
				DQ.pop_front();				
			}
		}
		else if (input == "pop_back") {
			if (DQ.empty()) cout << "-1" << "\n";
			else {
				cout << DQ.back() << "\n";
				DQ.pop_back();
			}
		}
		else if (input == "size") {
			cout << DQ.size() << "\n";
		}
		else if (input == "empty") {
			if(DQ.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (input == "front") {
			if (DQ.empty()) cout << "-1" << "\n";
			else {
				cout << DQ.front() << "\n";
			}
		}
		else if (input == "back") {
			if (DQ.empty()) cout << "-1" << "\n";
			else {
				cout << DQ.back() << "\n";
			}
		}
	}
	

	return 0;
}