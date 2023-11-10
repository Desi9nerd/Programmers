#include <queue>
#include <vector>
using namespace std;

int solution(int bl, int w, vector<int> tw) {
   
    queue<pair<int, int>> Q; // tw의 인덱스, 무게
    Q.push({ 0, tw[0] });
    int i = 1;
    int totalWeight = tw[0];
    int answer = 1; // answer: 현재시간

	while (true)
	{

        if (!Q.empty() && answer - Q.front().first == bl) // 현재시간 - i번째 트럭이 진입한 시간 == 다리의 길이
        {
            totalWeight -= Q.front().second;
            Q.pop();
        }

        if (i < tw.size() && totalWeight + tw[i] <= w)
        {
            Q.push({ answer, tw[i] }); // 트럭이 다리로 진입하는 시간을 저장
            totalWeight += tw[i];
            i++;
        }

        answer++;
        
        if (Q.empty() && i == tw.size()) break;
    }

    return answer;
}