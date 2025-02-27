#include <string>
#include <vector>

using namespace std;

// 주어진 영역이 모두 같은 값인지 확인하는 함수
bool isUniform(vector<vector<int>>& arr, int x, int y, int size, int& value) {
    value = arr[x][y]; // 첫 번째 값을 기준으로 설정
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != value) {
                return false; // 다른 값이 있으면 false 반환
            }
        }
    }
    return true;
}

void quadCompression(vector<vector<int>>& arr, int x, int y, int size, vector<int>& answer) {
    int value;
    if (isUniform(arr, x, y, size, value)) {
        answer[value]++; // 0 또는 1 개수 증가
        return;
    }

    int newSize = size / 2;
    quadCompression(arr, x, y, newSize, answer);             // 좌상단
    quadCompression(arr, x, y + newSize, newSize, answer);   // 우상단
    quadCompression(arr, x + newSize, y, newSize, answer);   // 좌하단
    quadCompression(arr, x + newSize, y + newSize, newSize, answer); // 우하단
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0); // 0의 개수, 1의 개수 저장
    int size = arr.size();
    quadCompression(arr, 0, 0, size, answer);
    return answer;
}
