#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
  
    map<string,int> myMap;
    myMap[words[0]]++;
    
    for(int i = 1; i < words.size(); i++) 
    {
        if(myMap[words[i]] || words[i].front()!= words[i-1].back())
            return {(i%n)+1, (i/n)+1};
        
        myMap[words[i]]++;
    }
    
    return {0,0};
}