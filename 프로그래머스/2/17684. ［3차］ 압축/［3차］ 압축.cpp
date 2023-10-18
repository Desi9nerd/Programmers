#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> myMap; // 사전 등록에 쓰일 map

vector<int> solution(string msg) {
    vector<int> answer;
    
    for(int i = 0; i < 26; i++) { // Initialize dictionary with A-Z
        string alphabet(1, 'A' + i);
        myMap[alphabet] = i+1;
    }

    int x = 27;
    for (int i = 0; i < msg.size(); ) {
        string temp(1, msg[i]);
        
        while(myMap.find(temp) != myMap.end() && i + temp.size() <= msg.size()) {
            temp += msg[i + temp.size()];
        }
        
        if(temp.size() > 1) { // If the string length is more than one
            myMap[temp] = x++; 
            temp.pop_back();
        }

        answer.push_back(myMap[temp]); 
        i += temp.size();
    }
    
    return answer;
}