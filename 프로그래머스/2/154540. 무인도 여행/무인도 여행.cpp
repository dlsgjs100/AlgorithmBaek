#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) 
{
    int rows = maps.size();
    int cols = maps[0].size();
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));
    vector<int> answer;
    
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    
    auto bfs = [&](int x, int y)
    {
        queue<pair<int,int>> q;
        q.push({x,y});
        visited[x][y] = true;
        int sum = maps[x][y] - '0';
        
        while(!q.empty())
        {
            auto [cx,cy] = q.front();
            q.pop();
            
            for(int d=0;d<4;d++)
            {
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                
                if(nx>=0 && nx<rows && ny>=0 && ny<cols &&
                  !visited[nx][ny] && maps[nx][ny] != 'X')
                {
                    visited[nx][ny] = true;
                    sum+=maps[nx][ny] - '0';
                    q.push({nx,ny});
                }
            }
        }
        return sum;
    };
    
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(!visited[i][j] && maps[i][j] != 'X')
            {
                answer.push_back(bfs(i,j));
            }
        }
    }
    
    if(answer.empty())
    {
        return {-1};
    }
    sort(answer.begin(), answer.end());
    return answer;
}