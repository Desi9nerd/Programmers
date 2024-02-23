#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> e)
{
    int answer = e.size(); // 모든 라운드를 통과하는 경우를 초기값으로 설정
    int sum = 0;

    priority_queue<int, vector<int>, greater<int>> pQ; // 오름차순
    
    for (int i = 0; i < e.size(); i++)
    {
        pQ.push(e[i]);

        if (pQ.size() > k) // 무적권보다 개수보다 크게 쌓이게되면
        {
            sum += pQ.top(); // 가장 작은값(=무적권을 사용하지 않고 무찌른 적 병사 수)을 더함 
            pQ.pop();       // 해당 경우는 무적권을 안 쓴 경우이니 빼준다
        }

        if (sum > n) { // 해치운 적의 수의 합 > 처음에 주어진 병사 수
            answer = i;
            break;
        }
    }

    return answer;
}