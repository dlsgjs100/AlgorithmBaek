#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    set<int> uniqueSums; // 중복 없는 합을 저장

    // 원형 배열 처리를 위해 elements를 두 배로 늘림
    elements.insert(elements.end(), elements.begin(), elements.end());

    // 부분 배열의 길이를 1부터 n까지 순회
    for (int len = 1; len <= n; len++) {
        for (int start = 0; start < n; start++) {
            int sum = 0;
            // 부분 배열의 합 계산
            for (int k = 0; k < len; k++) {
                sum += elements[start + k];
            }
            uniqueSums.insert(sum); // 중복 없이 저장
        }
    }

    return uniqueSums.size();
}
