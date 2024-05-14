#include <iostream>
#include <vector>
using namespace std;

vector<int> apeach(11), ryan(11);
vector<int> answer;
int maxDiff;

bool GivenLogic()
{
	for (int i = 10; i >=0; i--){
        if (answer[i] < ryan[i]) return true;
        if (answer[i] > ryan[i]) return false;
	}
}

void Cal(){
    int apeachScore = 0, ryanScore = 0;

    for (int i = 0; i <= 10; i++){
        if (apeach[i] == 0 && ryan[i] == 0) continue;

    	if (apeach[i] >= ryan[i]){
            apeachScore += (10 - i);
        }
        else if (apeach[i] < ryan[i]){
            ryanScore += (10 - i);
        }
    }

    // 어파치가 이긴 경우
    if (apeachScore >= ryanScore) {
        return;
    }

    // 라이언이 이긴 경우, 값을 업데이트
    if (maxDiff < ryanScore - apeachScore)
    {
        maxDiff = ryanScore - apeachScore; // 점수차 업데이트
        answer = ryan;
    }
    else if (maxDiff == ryanScore - apeachScore) // 점수차가 이전이랑 같은 경우
    {
	    if(GivenLogic()) // 작은 값이 더 많은지 확인
	    {
            maxDiff = ryanScore - apeachScore; // 점수차 업데이트
            answer = ryan;
	    }
    }

}

void DFS(int k, int remain)
{
    if (k == 11 || remain == 0){
        ryan[10] = remain;
    	Cal();
        ryan[10] = 0;
        return;
    }

    if (remain > apeach[k]){
        ryan[k] = apeach[k] + 1;
        DFS(k + 1, remain - (apeach[k] + 1));
        ryan[k] = 0;
    }
    DFS(k + 1, remain);
}

vector<int> solution(int n, vector<int> info) {

    apeach = info;

    DFS(0, n);

    if (answer.size() == 0) answer.push_back(-1);

    return answer;
}
