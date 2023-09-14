#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    map<string, vector<string>> myMap;

    for (int i=0; i<clothes.size(); i++){

        auto it = myMap.find(clothes[i][1]);
        if(it != myMap.end())
        {
            it->second.push_back(clothes[i][0]);
        }
        else
        {
            vector<string> inputTemp = { clothes[i][0] };
            myMap.insert({ clothes[i][1], inputTemp});	        
        }
    }

    vector<int> Items(myMap.size()); 
	int x = 0;
    for(auto iter = myMap.begin(); iter != myMap.end(); iter++)
    {
        Items[x++] = iter->second.size();
    }

    answer = 1;
    for (int i = 0; i < Items.size(); i++)
    {
        answer *= (Items[i] + 1); 
    }

    // 최소 한 개 이상 의상을 입으므로 전체에서 아무것도 안입은 상태(-1) 제외
    answer -= 1;

    return answer;
}