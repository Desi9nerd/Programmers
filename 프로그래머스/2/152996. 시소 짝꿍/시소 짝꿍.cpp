#include <unordered_map>
#include <vector>
using namespace std;

long long solution(vector<int> weights) {
    unordered_map<int, long long> weight_map; // 몸무게를 key로, 해당 몸무게를 가진 사람들의 수를 value로 하는 unordered_map 생성

    for (auto weight : weights) 
        weight_map[weight]++; // 각 몸무게에 대한 사람 수를 증가

    long long answer = 0;

    for (auto weight : weights)
    {
        long long value = weight * 2;
        if (weight_map.count(value)) // 1:2 (=2:4) 관계 체크
            answer += weight_map[value];

        if (weight % 2 == 0) {
            value = (weight / 2) * 3; // 2:3 관계 체크
            if (weight_map.count(value))
                answer += weight_map[value];
        }
        if (weight % 3 == 0) {
            value = (weight / 3) * 4; // 3:4 관계 체크
            if (weight_map.count(value))
                answer += weight_map[value];
        }
    }

    for (auto it : weight_map) 
    {
        if (it.second >= 2) 
            answer += it.second * (it.second - 1) / 2; // 몸무게가 같은 경우, 조합 공식 nC2를 이용해 쌍의 수를 구함
    }

    return answer;
}