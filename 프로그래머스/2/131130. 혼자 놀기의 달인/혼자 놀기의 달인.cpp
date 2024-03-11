#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cards)
{
    int n = cards.size();

    vector<bool> ch(n + 1, false); // 카드를 골랐는지 체크하는 bool 배열
    vector<int> scores;                      // 상자에 담긴 카드 수(=점수)를 기록하는 배열

    for (int i = 0; i < n; i++)
    {
        int now = cards[i];
    	int cnt = 0;
        while (false == ch[now]) // 아직 고른 카드가 아니라면
        {
            ch[now] = true;        // 선택한걸 체크
            now = cards[now - 1];  // 현재 카드 업데이트
            cnt++;                 // 개수++
        }

        if (cnt > 0) {
            scores.push_back(cnt); // 점수 추가
        }
    }

    if (scores.size() == 1) return 0; // 첫 시도에 모든 상자를 연 경우


    sort(scores.rbegin(), scores.rend()); // 내림차순 정렬

	return scores[0] * scores[1];
}