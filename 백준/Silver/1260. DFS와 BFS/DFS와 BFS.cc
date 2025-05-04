#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 정점의 개수 N (1~1000)
// 간선의 개수 M (1~10000)
// 탐색을 시작할 정점의 번호 V
// (양방향)간선이 연결하는 두 정점의 번호

// 정점 번호가 작은 것 먼저
// 더 방문할 수 없으면 종료 

class Graph
{
private:
    int n;
    vector<vector<int>> adj;
    vector<bool> visited;
public:
    Graph(int n) : n(n)
    {
        adj.resize(n+1);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void prepare() 
    {
        for (int i = 1; i <= n; ++i) 
        {
            sort(adj[i].begin(), adj[i].end()); 
        }
    }
    void dfs(int v) 
    {
        visited.assign(n + 1, false);
        dfsUtil(v);
        cout << '\n';
    }
    void bfs(int start) 
    {
        visited.assign(n + 1, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) 
        {
            int v = q.front(); q.pop();
            cout << v << ' ';

            for (int u : adj[v]) 
            {
                if (!visited[u]) 
                {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        cout << '\n';
    }
    
private:
    void dfsUtil(int v) 
    {
        visited[v] = true;
        cout << v << ' ';

        for (int u : adj[v]) 
        {
            if (!visited[u]) 
            {
                dfsUtil(u);
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,M,V;
    cin>>N>>M>>V;
    
    Graph g(N);

    for (int i = 0; i < M; ++i) 
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.prepare(); 

    g.dfs(V);   
    g.bfs(V);    

    return 0;
}