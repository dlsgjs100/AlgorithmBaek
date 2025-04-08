#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    // x1,y1 ~ x2,y2
    
    vector<vector<int>> arr(rows,vector<int>(columns,0));
    for(int i=0;i<rows;i++)
    {
        for(int j = 0;j<columns;j++)
        {
            arr[i][j] = (i * columns) + (j+1);
        }
    }
    
    for(vector<int>& query : queries)
    {
        int x1 = query[0]-1;
        int y1 = query[1]-1;
        int x2 = query[2]-1;
        int y2 = query[3]-1;
        
        int temp = arr[x1][y1];
        int minValue = temp;

        // x1,y1에서 x2-1,y1까지 +1,0
        for(int i = x1;i<x2;i++)
        {
            arr[i][y1] = arr[i+1][y1];
            minValue = min(minValue,arr[i][y1]);
        }
        // x2,y1에서 x2,y2-1까지 0,+1
        for (int i = y1; i < y2; i++) 
        {
            arr[x2][i] = arr[x2][i + 1];
            minValue = min(minValue, arr[x2][i]);
        }
        // x2,y2에서 x1+1,y2까지 -1,0
        for (int i = x2; i > x1; i--) 
        {
            arr[i][y2] = arr[i - 1][y2];
            minValue = min(minValue, arr[i][y2]);
        }
        // x1,y2에서 x1,y1+1까지 0,-1
        for (int i = y2; i > y1 + 1; i--) {
            arr[x1][i] = arr[x1][i - 1];
            minValue = min(minValue, arr[x1][i]);
        }
        arr[x1][y1 + 1] = temp;
        minValue = min(minValue, temp);
        
        answer.push_back(minValue);
    }
    return answer;
}