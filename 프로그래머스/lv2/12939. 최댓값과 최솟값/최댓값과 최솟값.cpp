#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) 
{
    string answer = "";

    stringstream SS(s);

    string tmp = "";
    vector<int> v;

    while (SS >> tmp) 
    {
        v.push_back(stoi(tmp));
    }

    sort(v.begin(), v.end());
    answer = to_string(v.front()) + " " + to_string(v.back());

    return answer;
}