#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int countNodes(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    int count = 1;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();

        for (int next : graph[current]) 
        {
            if (!visited[next]) 
            {
                visited[next] = true;
                q.push(next);
                count++;
            }
        }
    }

    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int minDiff = n;

    for (int i = 0; i < wires.size(); ++i) 
    {
        // 그래프 초기화
        vector<vector<int>> graph(n + 1);

        for (int j = 0; j < wires.size(); ++j) 
        {
            if (i == j) 
            {
                continue; // i번째 간선은 끊는다
            }
            int a = wires[j][0];
            int b = wires[j][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> visited(n + 1, false);
        int count = countNodes(1, graph, visited);
        int diff = abs(n - 2 * count);
        minDiff = min(minDiff, diff);
    }

    return minDiff;
}
