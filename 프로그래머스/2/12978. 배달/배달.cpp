#include <vector>
#include <queue>
using namespace std;

struct Edge{
    int city;
    int cost;
    Edge(int a, int b) {
        city = a;
        cost = b;
    }
    bool operator<(const Edge& e) const{
        return cost > e.cost;
    }
};

int solution(int n, vector<vector<int> > road, int k) {
    
    vector<int> dist(n + 1, 2147000000);
    priority_queue<Edge> pQ;
    pQ.push(Edge(1,0));
    dist[1] = 0;

    while (!pQ.empty())
    {
        int curLoc = pQ.top().city;
        int curCost = pQ.top().cost;
        pQ.pop();

        // 기존에 구한 최소비용보다 새로 구한 최소비용 클 경우 갱신하지 않고 continue
        if (dist[curLoc] < curCost) continue;

        for (int i = 0; i < road.size(); i++)
        {
            if (road[i][0] == curLoc || road[i][1] == curLoc){
                int nextLoc = road[i][0] == curLoc ? road[i][1] : road[i][0];
                int nextCost = curCost + road[i][2];
               
                if (dist[nextLoc] > nextCost)
                {
                    dist[nextLoc] = nextCost;
                    pQ.push(Edge(nextLoc, nextCost));
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i < dist.size(); i++) 
    {
        if (dist[i] <= k) answer++;
    }

    return answer;
}
