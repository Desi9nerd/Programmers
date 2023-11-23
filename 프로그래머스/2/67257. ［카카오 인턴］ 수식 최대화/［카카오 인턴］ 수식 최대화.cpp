#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v; // 숫자를 담는 배열 
vector<char> oper; // 연산자를 담는 배열
long long answer;

long long Calculate(long long a, long long b, char op)
{
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
}

long long solution(string ex) {
    int n = ex.size();

    string num = "";
    for(int i=0; i<n; i++)
    {
		if('0' <= ex[i] && ex[i] <= '9'){
            num += ex[i];
		}
        else{
            oper.push_back(ex[i]);      // 연산자 담기
            v.push_back(stoll(num)); // 숫자 담기
            num = "";
        }
    }
    v.push_back(stoll(num));

    vector<int> idx = { 0, 1, 2 };
    string op = "+-*";
    do{
        vector<long long> numValue = v;
        vector<char> tempOper = oper;
        for(int i = 0; i < 3; i++){
            for (int j = 0; j < tempOper.size();) {
		        if(tempOper[j] == op[idx[i]])
		        {
                    long long result = Calculate(numValue[j], numValue[j + 1], tempOper[j]);

                    numValue.erase(numValue.begin() + j);
                    numValue.erase(numValue.begin() + j); // 위의 삭제로 앞으로 한칸 땡겨져 왓을테니 그대로 j 위치 삭제
                    numValue.insert(numValue.begin() + j, result); // 위의 삭제로 앞으로 한칸 땡겨져 왓을테니 그대로 j 위치에 삽입

                    tempOper.erase(tempOper.begin() + j);
                    // 이 경우엔 j++ 하지 않는다. temp_operator 원소가 삭제되어서 앞으로 한 칸 땡겨졌을테니 그대로 다음 반복에서 j 인덱스 검사
                }
                else
                    j++;  // 이번 연산자 못 찾은 경우에만 j++
            }
        }
        answer = max(answer, abs(numValue[0])); // answer에는 최대값만 들어가게끔. 음수는 양수로 바꾼다 했으니 절대값만 취함.
    }
    while (next_permutation(idx.begin(), idx.end()));

    return answer;
}
