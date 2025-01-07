#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    // 명령 : "방향 거리"
    // 수행전 이동할 때  공원을 벗어나거나 장애물을 만나면
    // 무시하고 다음 명령 수행routes
    // 공원을 나타내는 문자열 배열 park
        // S : 시작 지점
        // O : 이동 가능한 통로
        // X : 장애물
    // 명령배열 routes
    // return : 모든 명령을 수행 후 로봇의 위치[세로, 가로]
    
    int width=0;
    int height=0;
    
    // 시작좌표 width,height
    for(int i=0;i<park.size();i++){
         for(int j=0;j<park[i].size();j++){
             if(park[i][j]=='S'){
                 height = i;
                 width = j;
             }
         }
    }
    
    
    // 공원을 벗어나는가 먼저 확인
    // 도중에 장애물을 만나는가 확인
    // E,W이동 -> width 변화
        
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    string orientations = "EWSN";
        
    for (const string& route : routes) {
        char direction = route[0];   // 방향
        int distance = route[2]-'0';
        int dirIdx = orientations.find(direction);
        int dx = directions[dirIdx].first;
        int dy = directions[dirIdx].second;

        // 이동 가능성 검증
        int newHeight = height, newWidth = width;
        bool isBlocked = false;

        for (int i = 0; i < distance; i++) {
            newHeight += dx;
            newWidth += dy;

            // 범위를 벗어나거나 장애물을 만날 경우
            if (newHeight < 0 || newHeight >= park.size() || 
                newWidth < 0 || newWidth >= park[0].size() || 
                park[newHeight][newWidth] == 'X') {
                isBlocked = true;
                break;
            }
        }

        // 이동 가능하면 위치 업데이트
        if (!isBlocked) {
            height = newHeight;
            width = newWidth;
        }
    }
    
    answer.push_back(height);
    answer.push_back(width);
    
    
    return answer;
}