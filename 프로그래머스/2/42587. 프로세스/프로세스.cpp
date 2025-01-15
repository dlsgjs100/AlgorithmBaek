#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i}); 
    }

    while (!q.empty()) {
        int currentPriority = q.front().first;
        int currentIndex = q.front().second;
        q.pop();

        bool hasHigherPriority = false;
        for (const auto& p : priorities) {
            if (p > currentPriority) {
                hasHigherPriority = true;
                break;
            }
        }

        if (hasHigherPriority) {
            q.push({currentPriority, currentIndex});
        } else {
            answer++;
            priorities.erase(find(priorities.begin(), priorities.end(), currentPriority)); 

            if (currentIndex == location) {
                return answer;
            }
        }
    }

    return answer;
}
