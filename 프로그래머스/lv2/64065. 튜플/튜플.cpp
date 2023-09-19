#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    map<int,int> m;
    int tmpNum = 0;
    
    for (int i = 1; i < s.size()-1; i++) 
    {
        if (s[i] == ',' || s[i] == '}') 
        {
            if(tmpNum != 0){
                m[tmpNum]++;
                tmpNum=0;
            }
        }

        if ('0' <= s[i] && s[i] <= '9') {            
             tmpNum *= 10;
             tmpNum += s[i]-'0';
        }
        
    }

    vector<pair<int,int>> pairs(m.begin(), m.end());
    
    sort(pairs.begin(), pairs.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    });
    
    vector<int> answer;
    
    for(auto &p: pairs){
        answer.push_back(p.first);
    }

   return answer;
}