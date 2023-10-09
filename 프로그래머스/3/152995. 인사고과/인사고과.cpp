#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Score
{
    int attitude;
    int coworker;
    int total;
    Score(int a, int b, int c) {
        attitude = a;
        coworker = b;
        total = c;
    }

    bool operator>(const Score& c) const {
        return total > c.total;
    }
};

vector<Score> v;
bool Dropped[100001];

int solution(vector<vector<int>> scores) {
    
    for (int i = 0; i < scores.size(); i++) {
        v.push_back({ scores[i][0], scores[i][1], scores[i][0] + scores[i][1] });
    }
    

    sort(v.begin(), v.end(), greater<Score>()); // total이 많은 순서로 정렬

    int answer = 1;
    for (int i = 0; i < v.size(); i++) 
    {
        for (int j = 0; j < i; j++) {
            if (v[j].attitude > v[i].attitude && v[j].coworker > v[i].coworker)
            {
                Dropped[i] = true;
                break;
            }
        }
        
        if (Dropped[i] == false && v[i].total > scores[0][0] + scores[0][1])
            answer++;

        // 완호의 석차
        if (Dropped[i] == false && v[i].attitude == scores[0][0] && v[i].coworker == scores[0][1]) {
            return answer;
        }
    }
    
    return -1;
}
