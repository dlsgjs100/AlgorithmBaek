#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int bfs(vector<vector<int>>& maze, int N, int M)
{
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front(); 
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir]; 
            int ny = y + dy[dir]; 

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (maze[nx][ny] == 1 && !visited[nx][ny])
                {
                    visited[nx][ny] = true;                    
                    maze[nx][ny] = maze[x][y] + 1;             
                    q.push({nx, ny});                          
                }
            }
        }
    }

    // 도착지 (N-1, M-1)의 거리 값 반환
    return maze[N - 1][M - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> maze(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j)
        {
            maze[i][j] = row[j] - '0'; 
        }
    }

    cout << bfs(maze, N, M) << '\n';

    return 0;
}
