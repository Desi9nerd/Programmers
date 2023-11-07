#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> strNums;

bool Compare(string& a, string& b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {

    for (int i = 0; i < numbers.size(); i++)
    {
        strNums.emplace_back(to_string(numbers[i]));
    }
    sort(strNums.begin(), strNums.end(), Compare);

    string answer;
    for(int i=0; i<strNums.size(); i++)
    {
        answer += strNums[i];
    }
    
    return answer[0] == '0' ? "0" : answer;
}