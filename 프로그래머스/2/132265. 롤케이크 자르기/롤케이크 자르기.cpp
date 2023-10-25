#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    map<int, int> map1;
    map<int, int> map2;

    for (int& i : topping) {
        map1[i]++;
    }

    for (int i = 0; i < topping.size() - 1; i++) 
    {
        map1[topping[i]]--;
        map2[topping[i]]++;

        if (map1[topping[i]] == 0)
            map1.erase(topping[i]);

        if (map1.size() == map2.size())
            answer++;
    }

    return answer;
}