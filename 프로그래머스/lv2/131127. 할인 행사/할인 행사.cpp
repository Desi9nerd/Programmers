#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    map<string, int> need; // 원하는 물품 종류와 수를 담는 map
    for(int i=0; i<want.size(); i++){
        need.insert(make_pair(want[i], number[i]));
    }

    for (int start = 0; start < discount.size(); start++){
		for (int i = start; i < start + 10 && i < discount.size(); i++)
	    {
	        //i번째 discount 물품이 원하는 물품 리스트에 있는지 확인
	        map<string,int>::iterator it = need.find(discount[i]);
	        if (it != need.end())
	        {
	            it->second--;
				//cout << it->first << " : " << it->second << "\n";

	            if (it->second == 0) // 해당 물품을 더 이상 살 필요 없다면
	                need.erase(it); // 물품 목록에서 없애준다.
	        }

	        if(need.empty()){
				answer++;
				//cout << "answer : " << answer << "\n";
				break;
	        }
	    }


		need.clear();
		for (int i = 0; i < want.size(); i++) {
			need.insert(make_pair(want[i], number[i]));
		}
    }

    return answer;
}
