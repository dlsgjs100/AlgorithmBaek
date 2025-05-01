#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<bool> visited;

void dfs(int depth) 
{
    if (depth == M) 
    {
        for (int num : arr)
        {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; ++i) 
    {
        if (!visited[i]) 
        {
            visited[i] = true;
            arr.push_back(i);
            dfs(depth + 1);
            arr.pop_back();
            visited[i] = false;
        }
    }
}

int main() 
{
    cin >> N >> M;
    visited.resize(N + 1, false);
    dfs(0);
    return 0;
}