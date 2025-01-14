#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    // 조합의 수 : 종류별 옷의 갯수들의 곱 - 1
    map<string, int> clothesMap;
    for(int i=0;i<clothes.size();i++){
        clothesMap[clothes[i][1]] = 1;
    }
    for(int i=0;i<clothes.size();i++){
        clothesMap[clothes[i][1]] ++;
    }
    for(auto it = clothesMap.begin() ; it!=clothesMap.end();it++){
        answer *= it->second;
    }
    answer--;
    return answer;
}