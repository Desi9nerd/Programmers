#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker){
    int n = sticker.size();

    vector<int> dp1(n); // 첫번째 선택O
    vector<int> dp2(n); // 첫번째 선택X

    dp1[0] = sticker[0];
    dp1[1] = sticker[0];

    dp2[1] = sticker[1];

    for (int i = 2; i < n; i++)
    {
        dp1[i] = max(dp1[i - 2] + sticker[i], dp1[i - 1]);
        dp2[i] = max(dp2[i - 2] + sticker[i], dp2[i - 1]);

        if (i == n - 1) {
            dp1[i] = max(dp1[i - 2], dp1[i - 1]);
        }
    }

    int answer = max(dp1[n - 1], dp2[n - 1]);

    return answer;
}