#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> answer;
map<string, int> myMap;
int ch[10];

bool Compare(const string& s1, const string& s2)
{
    return s1 < s2;
}

void Combination(string ord, string str, int idx, int select)
{
	if(str.size() == select){
        sort(str.begin(), str.end());
        myMap[str]++;
        return;
	}

    for(int i = idx; i<ord.size(); i++)
    {
        if (ch[i] == 0)
        {
            ch[i] = 1;
            Combination(ord, str + ord[i], i + 1, select);
            ch[i] = 0;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
        
    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < course.size(); j++) {
            Combination(orders[i], "", 0, course[j]);
        }
    }

    for (int i = 0; i < course.size(); i++)
    {
        int max_value = 0;
        for (const auto& it : myMap) {
            if (it.first.size() == course[i] && it.second > 1 && it.second > max_value) {
                max_value = it.second;
            }
        }
        for (const auto& it : myMap) {
            if (it.first.size() == course[i] && it.second == max_value) {
                answer.push_back(it.first);
            }
        }
    }

    sort(answer.begin(), answer.end(), Compare);

    return answer;
}
