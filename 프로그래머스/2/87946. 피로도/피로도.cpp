#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int maxDungeons = 0;
    
    // 모든 던전 순서를 순열로 탐색
    sort(dungeons.begin(), dungeons.end());
    do {
        int currentK = k;
        int count = 0;
        
        // 현재 순열의 던전 순서에 따라 탐험
        for (const auto& dungeon : dungeons) {
            int required = dungeon[0];
            int consume = dungeon[1];
            
            if (currentK >= required) {
                currentK -= consume;
                count++;
            } else {
                break; // 더 이상 탐험 불가
            }
        }
        
        // 최대 던전 수 갱신
        maxDungeons = max(maxDungeons, count);
        
    } while (next_permutation(dungeons.begin(), dungeons.end())); // 다음 순열 생성
    
    return maxDungeons;
}
