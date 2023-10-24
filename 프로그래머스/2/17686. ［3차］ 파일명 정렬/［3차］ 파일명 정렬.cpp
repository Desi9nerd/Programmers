#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct File{
    string head;
    int number;
	int index;

    File(string a, int b, int c)
    {
        head = a; number = b; index = c;
    }

    bool operator<(const File& f) const
	{
        if(head != f.head){
            return head < f.head;
        }
        if(number != f.number){
            return number < f.number;
        }
        return index < f.index;
    }
};

vector<File> v;

vector<string> solution(vector<string> files) {
    vector<string> answer;

	for(int i = 0; i<files.size(); i++){
		string str = files[i];
		string head = "", num_str="";
		int j=0;

		while(j<str.size()){
			if(isdigit(str[j])) break;
			head += tolower(str[j]);
			j++;
		}

		while(j<str.size()){
			if(!isdigit(str[j])) break;
			num_str += str[j];
			j++;
		}

    	v.push_back({head , stoi(num_str), i});
   }

	sort(v.begin(), v.end());

	for(int i=0;i<v.size();i++){
    	answer.push_back(files[v[i].index]);
   }

	return answer;
}