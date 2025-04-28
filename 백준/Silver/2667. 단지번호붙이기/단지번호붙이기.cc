#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int dfs(vector<vector<int>>& maps, vector<vector<bool>>& visited, int x, int y, int N)
{
    visited[x][y] = true;
    int houseCount = 1; // 현재 집 1개 세고 시작

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 범위 체크
        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        {
			// 방문하지 않았고 집이 있는 곳이면 dfs 탐색
            if (maps[nx][ny] == 1 && visited[nx][ny] == false)
            {
                houseCount += dfs(maps, visited, nx, ny, N);
            }
        }
    }
    return houseCount;
}

int main()
{
    int N; // 5~25
    cin >> N;

    vector<vector<int>> maps(N, vector<int>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    // N줄에 각각 N개의 자료
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++)
        {
            maps[i][j] = line[j] - '0';
        }
    }

    vector<int> ans;
    // 단지 수 세기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
			// 방문하지 않았고 집이 있는 곳이면 dfs 탐색
            if (maps[i][j] == 1 && !visited[i][j])
            {
                int houseCount = dfs(maps, visited, i, j, N);
                ans.push_back(houseCount);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n"; // 총 단지 수
    for (int num : ans)
    {
        cout << num << "\n"; // 각 단지 내 집 수
    }
}