#include <string>
#include <vector>
using namespace std;

int solution(string word) {
    int answer = word.length(); 
    vector<int> nums = { 781, 156, 31, 6, 1 };
    string vowels = "AEIOU";

    for(int i = 0; i < word.size(); i++){
	    for(int j=0; j < 5; j++)
	    {
            if (word[i] == vowels[j])  // 일치하는 모음을 찾으면
                answer += nums[i] * j; // 5진수 수 answer에 값을 넣어줌. 해당 자리의 숫자값 = nums[i] * j.
	    }
    }

    return answer;
}