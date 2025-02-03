#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    vector<int> stack;

    for (int i = numbers.size() - 1; i >= 0; i--) {
        // 스택에 numbers[i]보다 큰 수만 남긴다.
        while (!stack.empty() && stack.back() <= numbers[i]) {
            stack.pop_back();
        }

        // 스택이 비어있지 않다면, 스택의 top이 가장 가까이 있다.
        if (!stack.empty()) {
            answer[i] = stack.back();
        }

        // 현재 원소를 스택에 추가
        stack.push_back(numbers[i]);
    }

    return answer;
}
