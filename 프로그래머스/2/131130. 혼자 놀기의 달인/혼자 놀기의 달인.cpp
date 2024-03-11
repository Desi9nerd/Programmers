#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cards) {
    
    int n = cards.size();

    if (n < 1) return 0;

    vector<int> scores;
    int i = 0;
    while(n > 0)
    {
        set<int> mySet;
        while (true)
        {
            if (cards[i] == -1){
                i++;
                break;
            }

        	if (mySet.find(cards[i]) == mySet.end()) {
                mySet.insert(cards[i]);
                //cout << cards[i] << " ";
                int tmp = i;
                i = cards[tmp] - 1;
                cards[tmp] = -1;
                n--;
            }
            else {
                break;
            }
        }
        //cout << "\n";
        scores.push_back(mySet.size());
    }

    if (scores.size() == 1) return 0; // 첫 시도에 모든 상자를 연 경우

    sort(scores.rbegin(), scores.rend());

    return scores[0] * scores[1];
}