#include <vector>
using namespace std;

vector<long long> solution(vector<long long> numbers){
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++) 
    { 
        if (numbers[i] % 2 == 0) { // 짝수
            answer.push_back(numbers[i] + 1); // 다음 큰 숫자를 answer에 추가
        }
        else { // 홀수
            long long bit = 1;
            while (true) 
            {
                if ((numbers[i] & bit) == 0) break;
                bit *= 2;
            }
            bit = bit / 2;

            answer.push_back(numbers[i] + bit);
        }
    }

    return answer; 
}