#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle(n, vector<int>(n, 0)); // n x n 배열 초기화
    int col = 0, row = 0, count = 0; // 초기 위치 및 숫자

    for (int size = n; size > 0; size -= 3) 
    {
        // 아래로 이동
        for (int i = 0; i < size; i++) 
            triangle[col++][row] = ++count;
        
        col--; // 마지막 이동 위치 조정
        row++; // 다음 시작 위치 조정
        
        // 오른쪽으로 이동
        for (int i = 0; i < size - 1; i++) 
        {
            triangle[col][row++] = ++count;
        }
        
        row -= 2; // 마지막 위치 조정
        col--; // 다음 시작 위치 조정

        // 왼쪽 위 대각선 이동
        for (int i = 0; i < size - 2; i++) 
        {
            triangle[col--][row--] = ++count;
        }

        // 다음 시작 위치 조정
        col += 2;
        row++;
    }

    // 2차원 벡터에서 필요한 값만 1차원 벡터로 변환
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            answer.push_back(triangle[i][j]);
        }
    }

    return answer;
}
