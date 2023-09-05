#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    
    set<int> mySet;
    
    int n = elements.size();
    while (n>0)
    {
        //수열의 전체 개수만큼 for문 실행
        for(int i=0; i<elements.size(); i++)
        {
            int sum = 0;
            //n개 숫자의 연속 부분 수열의 합을 차례대로 구한다.
            for (int j = i; j < i+n; j++)
            {
                if (j < elements.size())
                    sum += elements[j];
                else
                    sum += elements[j - elements.size()];
            }
            //cout << "\n";
            //cout << "sum: " << sum << "\n";
            mySet.insert(sum);//구한 연속 부분 수열의 합을 set에 넣어준다.
        }

        n--;
    }

  // for (const auto& i : mySet)
   //    cout << "Set 부분수열합 : " << i << "\n";

    answer = mySet.size();

   // cout << "answer : " << answer;

    return answer;
}
