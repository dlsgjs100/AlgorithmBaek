#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int current=0;
    
    for (int i = 0; i < section.size(); i++) {
        if (section[i] > current) {
            current = section[i] + m - 1; // 현재 위치에서 m 길이만큼 칠함
            answer++;
        }
    }
    
    return answer;
}