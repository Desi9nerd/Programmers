#include <string>
#include <set>
using namespace std;

set<int> mySet;
int ch[1000001];

bool Check(int x)
{
    if (x <= 1) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;

    for(int i = 5; i * i <= x; i++)
    {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    
    return true;
}

void DFS(string& numbers, string s, int x, int n)
{
    if(x == n){                
        return;
    }
    
    for(int i=0; i<n; i++)
    {
        if (ch[i] == 0)
        {
            ch[i] = 1;

            mySet.insert(stoi(s + numbers[i]));
            DFS(numbers, s + numbers[i], x+1, n);

            ch[i] = 0;
        }
    }
}

int solution(string numbers) {

    int n = numbers.size();

    DFS(numbers, "", 0, n);


    int answer = 0;

    for(const auto& num : mySet)
    {
        if (Check(num)) answer++;
    }

    return answer;
}