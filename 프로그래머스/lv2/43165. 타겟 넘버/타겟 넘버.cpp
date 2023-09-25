#include <string>
#include <vector>
using namespace std;

int answer; // 타겟 넘버를 만드는 방법의 수
int ch[21]; // 방문 체크 배열

void DFS(int x, int sum, int target, vector<int>& numbers)
{
    if(x == numbers.size()){
        if(sum == target){
            answer++;
        }
        return;
    }
       
    DFS(x + 1, sum + numbers[x], target, numbers);
    DFS(x + 1, sum - numbers[x], target, numbers);   
}

int solution(vector<int> numbers, int target) {
  
    DFS(0, 0, target, numbers);

    return answer;
}