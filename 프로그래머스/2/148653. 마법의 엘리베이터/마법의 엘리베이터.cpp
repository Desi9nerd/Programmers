#include <string>
#include <vector>
using namespace std;

int solution(int storey) {
    
    vector<int> level;
    while(storey){
        level.push_back(storey % 10);
        storey /= 10;
    }

    int cnt = 0;
    for (int i = 0; i < level.size(); i++)
    {
        if (level[i] == 10){
            if (i == level.size() - 1) cnt += 1;
            else
                level[i + 1] += 1;
        }
        else if (5 < level[i] && level[i] < 10) {
            cnt += 10 - level[i];

            if (i == level.size() - 1) cnt += 1;
            else
                level[i + 1] += 1;
        }
        else if (5 == level[i]){
            if (i < level.size() - 1 && 5 <= level[i + 1]) {
                cnt += 10 - level[i];

                if (i == level.size() - 1) cnt += 1;
                else
                    level[i + 1] += 1;
            }
            else
                cnt += level[i];
        }
        else {
            cnt += level[i];
        }
    }
    
    return cnt;
}