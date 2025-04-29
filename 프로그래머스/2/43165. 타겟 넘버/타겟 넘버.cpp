#include <vector>
using namespace std;

void dfs(const vector<int>& numbers, int index, int target, int& answer) {
    if (index == numbers.size()) {
        if (target == 0) answer++;
        return;
    }
    dfs(numbers, index + 1, target - numbers[index], answer);
    dfs(numbers, index + 1, target + numbers[index], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, 0, target, answer);
    return answer;
}
