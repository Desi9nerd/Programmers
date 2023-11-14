#include <queue>
#include <vector>
using namespace std;

queue<int> Q1, Q2;
long long sum1, sum2, sumNum;
int answer;

int solution(vector<int> queue1, vector<int> queue2) {
	int n = queue1.size();
	for(int i=0; i<n; i++){
		sumNum += queue1[i];
		sum1 += queue1[i];
		Q1.push(queue1[i]);
	}
	for(int i=0; i<n; i++){
		sumNum += queue2[i];
		sum2 += queue2[i];
		Q2.push(queue2[i]);
	}

	bool success = false;
	int maxTrial = 3 * n;
	while (maxTrial--)
	{
		if(sum1 == sum2){
			success = true;
			break;
		}
		else if(sum1 < sum2){
			sum1 += Q2.front();
			sum2 -= Q2.front();
			Q1.push(Q2.front());
			Q2.pop();
		}
		else{
			sum1 -= Q1.front();
			sum2 += Q1.front();
			Q2.push(Q1.front());
			Q1.pop();
		}
        
		answer++;
	}

	if (false == success) answer = -1;

    return answer;
}
