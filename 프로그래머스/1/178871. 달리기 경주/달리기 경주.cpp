#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    // 이름을 불렀다 = 추월했다.
/*
    for(int i=0;i<callings.size();i++){
        for(int j=0;j<players.size();j++){
            if(players[j]==callings[i]){
                swap(players[j],players[j-1]);
            }
        }
    }
    
    answer = players;*///시간초과

    map<string, int> rank;
    vector<string> rankToPlayer(players.size() + 1);

    // 1. 초기 순위 설정
    for (int i = 0; i < players.size(); i++) {
        rank[players[i]] = i + 1;  // 선수 이름을 key로 등수를 저장
        rankToPlayer[i + 1] = players[i];  // 등수로 선수 이름 저장
    }

    // 2. callings에 따라 순위 업데이트
    for (const string& name : callings) {
        int curRank = rank[name];  // 호출된 선수의 현재 순위
       
        string frontPlayer = rankToPlayer[curRank - 1];  // 앞선 선수 이름
        // 순위 변경
        swap(rank[name], rank[frontPlayer]);
        // rankToPlayer 배열 업데이트
        rankToPlayer[curRank] = frontPlayer;
        rankToPlayer[curRank - 1] = name;
        
    }

    // 3. 최종 순위 기반으로 선수 이름 정렬
    for (int i = 1; i <= players.size(); i++) {
        answer.push_back(rankToPlayer[i]);
    }
    
    return answer;
}