
#include <string>
#include <vector>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int time = 0;
       
    if (cacheSize == 0)
        return cities.size() * 5;
    
    //대문자 -> 소문자 변환
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].length(); j++)
        {
            if (isupper(cities[i][j]))
                cities[i][j] = tolower(cities[i][j]);
        }
    }
    
    vector<string> LRU(cacheSize);
    
    for (int i = 0; i < cities.size(); i++) 
    {
        int pos = -1;//pos변수 추가. 중복값이 있을때 위치를 알려주는 변수
    
        for (int j = 0; j < cacheSize; j++) {
            if (cities[i] == LRU[j])
                pos = j;
        }

        //cache miss
        if (pos == -1) {
            for (int j = cacheSize - 1; j >= 1; j--) {
                LRU[j] = LRU[j - 1];
            }
            time += 5;
        }
        //cache hit
        else{
            for (int j = pos; j >= 1; j--) {
                LRU[j] = LRU[j - 1];
            }
            time += 1;
        }
        LRU[0] = cities[i];
    }


    return time;
}