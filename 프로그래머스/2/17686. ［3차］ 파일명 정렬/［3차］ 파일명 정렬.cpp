#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct File{
    string head;
    int number;
    string tail;
	int index;

    File(string a, int b, string c, int d)
    {
        head = a; number = b; tail = c; index = d;
    }

    bool operator<(const File& f)
	{
        if (head != f.head) {
            return head < f.head;
        }
        if (number != f.number) {
            return number < f.number;
        }
        return index < f.index;
    }
};

vector<File> v;

vector<string> solution(vector<string> files) {
    vector<string> answer;

    for(int i = 0; i < files.size(); i++)
    {
        string str = files[i];

        for (char& c : str) {
            if(isupper(c))
				c = tolower(c);
        };

        string head = "", tail = "";
        int number=0;
        bool flag = false;
        int tmp = 0;

    	for(int j = 0; j < str.size(); j++)
        {
            if ('0' <= str[j] && str[j] <= '9' && flag == false) {
                tmp = j;
                flag = true;
	        }
            else if (!('0' <= str[j] && str[j] <= '9') && flag == true) {
                head = str.substr(0, tmp);
                number = stoi(str.substr(tmp, j-tmp));
                tail = str.substr(j);
                break;
            }

            if (j == str.size() - 1) { // 마지막 문자열인 경우
                if (flag) { // 숫자가 이미 나온 경우
                    head = str.substr(0, tmp);
                    number = stoi(str.substr(tmp));
                    tail = "";
                }
            }
        }

        v.push_back({ head, number, tail, i });
    }

    sort(v.begin(), v.end());

	for(int i = 0; i<v.size(); i++){
        answer.push_back(files[v[i].index]);
	}

    return answer;
}
