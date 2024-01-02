#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string input, boom;
	cin >> input >> boom;

	vector<char> v;

	for(int i = 0; i < input.size(); i++)
	{
		v.push_back(input[i]);

		if(v.size() >= boom.size())
		{
			bool found = true;

			for(int j = 0; j < boom.size(); j++)
			{
				if(v[v.size() - boom.size() + j] != boom[j])
				{
					found = false;
					break;
				}
			}

			if(found)
				for(int j = 0; j < boom.size(); j++)
					v.pop_back();
		}
	}

	if(v.empty())
		cout << "FRULA";
	else{
		for(int i = 0; i < v.size(); i++)
			cout << v[i];
    }

	return 0;
}