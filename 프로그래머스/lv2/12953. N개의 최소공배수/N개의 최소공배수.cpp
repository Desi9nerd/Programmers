#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
      int answer = *max_element(arr.begin(), arr.end()) - 1;

    while (true)
    {
        answer++;

        for (int i = 0; i < arr.size(); i++) {
            if (answer % arr[i] != 0) break;
            if (i == arr.size() - 1) return answer;
        }
    }

}