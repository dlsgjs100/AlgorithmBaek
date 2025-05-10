#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = 2e9;

vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& graph) 
{
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) 
    {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] < cost) 
        {
            continue;
        }

        for (auto [next, weight] : graph[now]) 
        {
            int nextDist = cost + weight;
            if (nextDist < dist[next]) 
            {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }

    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<pair<int, int>>> graph(n + 1);
    
    for (auto& fare : fares) 
    {
        int u = fare[0], v = fare[1], w = fare[2];
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    auto distFromS = dijkstra(s, n, graph);
    auto distFromA = dijkstra(a, n, graph);
    auto distFromB = dijkstra(b, n, graph);

    int minCost = INF;
    for (int i = 1; i <= n; ++i) 
    {
        if (distFromS[i] == INF || distFromA[i] == INF || distFromB[i] == INF) 
        {
            continue;
        }
        minCost = min(minCost, distFromS[i] + distFromA[i] + distFromB[i]);
    }

    return minCost;
}
