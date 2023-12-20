#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
vector<int> dist(100001, 2147000000);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    deque<int> dQ;
    dQ.push_front(n);
    dist[n] = 0;

    while (!dQ.empty())
    {
        int x = dQ.front();
        dQ.pop_front();

        if (x == k) break;

        if (x * 2 < 100001 && dist[x * 2] > dist[x]) {
            dQ.push_front(x * 2);
            dist[x * 2] = dist[x];
        }
        if (x + 1 < 100001 && dist[x + 1] > dist[x] + 1) {
            dQ.push_back(x + 1);
            dist[x + 1] = dist[x] + 1;
        }
        if (x - 1 >= 0 && dist[x - 1] > dist[x] + 1) {
            dQ.push_back(x - 1);
            dist[x - 1] = dist[x] + 1;
        }
    }   

    cout << dist[k] << "\n";

    return 0;
}
