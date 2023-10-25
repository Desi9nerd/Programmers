#include <map>
#include <vector>
using namespace std;

map<int, int> myMap, newMap; // key: 토핑의 종류, value: 해당 토핑의 개수

int solution(vector<int> topping) {
    int answer = 0;
    
    for(int i = 0; i < topping.size(); i++)
    {    
        if(myMap.find(topping[i]) != myMap.end()) // 이전에 등장한 토핑 종류인지 검색
        {
            myMap[topping[i]]++; // 해당 토핑의 개수 증가
        }
        else
        {
            myMap.insert({ topping[i], 1 }); // 새로운 토핑 종류(key)와 해당 토핑의 개수(value) 기록
        }      
    }
        
    for (int i = 0; i < topping.size(); i++)
    {
        if(myMap.find(topping[i]) != myMap.end())
        {
            myMap[topping[i]]--; // 해당 토핑의 개수 감소

            if (myMap[topping[i]] == 0) 
                myMap.erase(topping[i]); // 0이 되면 myMap에서 지워준다.

            // 새로운 맵(newMap)에 토핑을 등록 또는 개수를 증가 시킨다.
            if (newMap.find(topping[i]) == newMap.end())
                newMap.insert({ topping[i], 1 });
            else
                newMap[topping[i]]++;
        }

        //** 만약 myMap.size() == newMap.size() 되는 경우가 없으면 answer이 증가되지 않아 초기 설정값인 0이 유지된다.
        //  myMap.size()는 계속해서 작아지고, newMap.size()는 계속해서 커진다.
        if (myMap.size() == newMap.size())
            answer++; // 옮겨지는 과정에서 myMap.size() == newMap.size()이 유지되는 상황에서는 계속 카운팅한다.  
    }
    
    return answer; 
}