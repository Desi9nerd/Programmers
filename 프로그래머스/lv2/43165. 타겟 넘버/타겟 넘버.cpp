#include <string>
#include <vector>
#include <queue>
using namespace std;

int answer; // 타겟 넘버를 만드는 방법의 수

queue<pair<int,int>> Q;

//void DFS(int x, int sum, int target, vector<int>& numbers)
//{
//    if(x == numbers.size()){
//        if(sum == target){
//            answer++;
//        }
//        return;
//    }
//       
//    DFS(x + 1, sum + numbers[x], target, numbers);
//    DFS(x + 1, sum - numbers[x], target, numbers);   
//}

void BFS(vector<int>& nums, int target)
{
    Q.push({ 0,-nums[0] });   // - 넣기
    Q.push({ 0,nums[0] }); // + 넣기

    while (!Q.empty()) {
        int idx = Q.front().first;
        int total = Q.front().second;
        Q.pop();

        if (idx == nums.size() - 1 && total == target) {
            answer++;
            continue;
        }
        if (idx == nums.size() - 1 && total != target) {
            continue;
        }
               
        Q.push({ idx + 1, total + (-1 * nums[idx + 1]) });
        Q.push({ idx + 1, total + (nums[idx + 1]) });
    }
}

int solution(vector<int> numbers, int target) {
  
    //DFS(0, 0, target, numbers);
    BFS(numbers, target);

    return answer;
}