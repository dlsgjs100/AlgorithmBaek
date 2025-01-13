#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int rows = arr1.size();          // arr1의 행 개수
    int cols = arr2[0].size();       // arr2의 열 개수
    int common = arr2.size();        // arr1의 열 개수와 arr2의 행 개수(같아야 함)
    
    vector<vector<int>> answer(rows, vector<int>(cols, 0)); // 결과 행렬 초기화

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < common; k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return answer;
}
