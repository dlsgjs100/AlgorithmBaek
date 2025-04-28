#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 상하좌우 탐색을 위한 배열
const int dx[4] = { 0,0,-1,1 };
const int dy[4] = { -1,1,0,0 };

// 전역변수 선언으로 인자 최소화
int N;
vector<vector<int>> maps;
vector<int> answer;

int dfs(int x, int y)
{
    // 현재 집 1개 세고 시작
    int houseCount = 1;
    maps[x][y] = 0; // 방문 표시

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // 범위 안에 있고 방문하지 않은 집이면 dfs 탐색
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && maps[nx][ny] == 1)
        {
            houseCount += dfs(nx, ny);
        }
    }
    return houseCount;
}

int main()
{
    cin >> N;
    maps.resize(N, vector<int>(N));
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
    // 단지 수 세기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 방문하지 않은 집이면 dfs 탐색
            if (maps[i][j] == 1)
            {
                answer.push_back(dfs(i, j));
            }
        }
    }
    // 오름차순 정렬
    sort(answer.begin(), answer.end());
    // 총 단지 수
    cout << answer.size() << "\n";
    for (int c : answer)
    {
        // 각 단지 내 집 수
        cout << c << "\n";
    }
    return 0;
}