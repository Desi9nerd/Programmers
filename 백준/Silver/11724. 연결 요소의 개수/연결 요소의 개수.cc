#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[1001];
int visited[1001];
int n, m;

void BFS(int start)
{    
    queue<int> Q;
    Q.push(start);
    visited[start] = 1;

    while (!Q.empty())
    {
        int current = Q.front();
        Q.pop();
        for (int i = 0; i < v[current].size(); i++)
        {
            if (visited[v[current][i]] == 0)
            {
                visited[v[current][i]] = 1; 
                Q.push(v[current][i]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int cnt = 0; 
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    //빠짐없이 탐색하기 위해
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            BFS(i);
            cnt++;
        }
    }
    cout << cnt;
}