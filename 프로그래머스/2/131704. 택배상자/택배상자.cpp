#include <stack>
#include <vector>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;

	stack<int> st;
	int j = 0;
	for(int i=0; i<order.size(); i++)
	{
		if (i + 1 == order[j]){
			j++;
			answer++;
		}
		else{
			st.push(i+1);
		}

		while(!st.empty())
		{
			if (st.top() == order[j]) {
				st.pop();
				j++;
				answer++;
			}
			else break;
		}
	}

	return answer;
}
