#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> answer(2);
int discount[4] = { 10, 20, 30, 40 };
vector<pair<int, int>> price(7);

void DFS(int idx, const vector<vector<int>>& users, const vector<int>& emo)
{
    if(idx == m)
    {
        int ppl = 0, sumPrice = 0;
        for(int i = 0; i < n; i++)
        {
            int temp = 0;
	        for(int j = 0; j < m; j++){
		        if(users[i][0] <= price[j].second){ // 할인율을 만족해 이모티콘을 구입하는 경우
                    temp += price[j].first;
		        }
	        }

            if(temp >= users[i][1]){
                ppl++;
            }
            else{
                sumPrice += temp;
            }
        }

        if(answer[0] < ppl){
            answer[0] = ppl;
            answer[1] = sumPrice;
        }
        else if (answer[0] == ppl && answer[1] <= sumPrice) {
            answer[1] = sumPrice;
        }

        return;
    }
	
    for (int i = 0; i < 4; i++)
    {
        price[idx].first = (100 - discount[i]) * emo[idx] / 100; // 할인된 이모티콘 가격
        price[idx].second = discount[i]; // 할인율
        DFS(idx + 1, users, emo);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emo) {
    n = users.size();
    m = emo.size();

    DFS(0, users, emo);

    return answer;
}
