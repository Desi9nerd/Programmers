#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    map<string, int> need, temp; // 원하는 물품 종류와 수를 담는 map
    for(int i=0; i<want.size(); i++){
        need.insert(make_pair(want[i], number[i]));
    }

    for (int start = 0; start < discount.size(); start++)
	{
		temp = need; //need와 똑같은 map을 사용하여 검사를 진행한다. 

		for (int i = start; i < start + 10 && i < discount.size(); i++)
	    {
	        //i번째 discount 물품이 원하는 물품 리스트에 있는지 확인
	        map<string,int>::iterator it = temp.find(discount[i]);
	        if (it != temp.end())
	        {
	            it->second--;

	            if (it->second == 0) // 해당 물품을 더 이상 살 필요 없다면
					temp.erase(it); // 물품 목록에서 없애준다.
	        }

			//물품 목록이 모두 비워졌다면 문제 조건을 달성했다는 의미다.
	        if(temp.empty()){
				answer++;//카운팅 해준다.
				break;
	        }
	    }

		//위에서 사용한 need를 비워주고 초기화해준다.
		//need.clear();
		//for (int i = 0; i < want.size(); i++) {
		//	need.insert(make_pair(want[i], number[i]));
		//}
    }

    return answer;
}