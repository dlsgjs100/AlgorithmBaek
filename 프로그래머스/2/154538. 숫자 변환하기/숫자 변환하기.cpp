#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) {
    if (x == y) return 0;  // 이미 같은 값이면 연산 필요 없음
    
    queue<pair<int, int>> q;  // {현재 값, 연산 횟수}
    unordered_set<int> visited;  // 방문한 숫자 저장

    q.push({x, 0});
    visited.insert(x);

    while (!q.empty()) 
    {
        int curr = q.front().first;
        int count = q.front().second;
        q.pop();

        // 가능한 연산 수행
        for (int next : {curr + n, curr * 2, curr * 3}) 
        {
            if (next == y) return count + 1;  // 목표 도달 시 즉시 반환
            if (next < y && visited.find(next) == visited.end()) 
            { 
                q.push({next, count + 1});  // 연산 결과를 큐에 추가
                visited.insert(next);  // 중복 방지
            }
        }
    }
    
    return -1;  // y에 도달할 수 없는 경우
}
