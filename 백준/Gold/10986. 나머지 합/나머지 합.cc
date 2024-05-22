#include <iostream>
#include <vector>
using namespace std;
      
long long sum, answer; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, temp;
    vector<long long> v(1001, 0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        sum += temp;
        v[sum % M]++;                   // 해당 i구간까지의 누적합
        if (sum % M == 0)
        {
            answer++;                   // M으로 나누어 떨어지면 ++
        }
    }
    for (int i = 0; i <= M; i++)
    {
        answer += v[i] * (v[i] - 1) / 2;    // nC2의 느낌으로 풀어야 한다. 설명은 블로그에 !!!
    }

    cout << answer;

    return 0;
}