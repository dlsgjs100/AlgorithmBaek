#include <iostream>
#include <vector>

using namespace std;

void dfs(int x, int y, int n, int m, vector<vector<int>>& ground, vector<vector<bool>>& visited)
{
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (visited[x][y] || ground[x][y] == 0) return;
	visited[x][y] = true;
	// 상하좌우 탐색
	dfs(x + 1, y, n, m, ground, visited);
	dfs(x - 1, y, n, m, ground, visited);
	dfs(x, y + 1, n, m, ground, visited);
	dfs(x, y - 1, n, m, ground, visited);
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int M, N, K;
		cin >> M >> N >> K;
		// 밭을 2차원 배열로 표현하고 배추가 있는 곳을 1, 없는 곳을 0으로 
		vector<vector<int>> ground(M, vector<int>(N, 0));
		vector<vector<bool>> visited(M, vector<bool>(N, false));
		while (K--)
		{
			// 배추의 위치 X,Y
			int X, Y;
			cin >> X >> Y;
			ground[X][Y] = 1;
		}

		int wormCount = 0;
		// 배추밭을 탐색하며 지렁이의 개수를 세기
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// 방문하지 않았고 배추가 있는 곳이면 dfs 탐색 시작
				if (visited[i][j] == false && ground[i][j] == 1)
				{
					dfs(i, j, M, N, ground, visited);
					wormCount++;
				}
			}
		}
		cout << wormCount << "\n";
	}
	return 0;
}