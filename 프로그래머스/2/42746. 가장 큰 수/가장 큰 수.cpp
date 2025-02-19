#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string solution(vector<int> numbers) {
    string answer = "";
    // 정렬: 두 숫자를 문자열로 변환 후 조합하여 비교
    sort(numbers.begin(), numbers.end(), compare);
    // 모든 숫자를 이어붙이기
    for(int num : numbers) {
        answer += to_string(num);
    }
    if(answer[0] == '0')
    {
        answer = '0';
    }

    return answer;
}
