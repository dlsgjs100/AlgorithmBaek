#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int answer1 = 0;
    int answer2 = 0;
    
    // 여벌이 있는데 도둑맞았을 경우 나부터
    // 내 뒤사람이 도둑맞았는데 여벌있으면 뒷사람
    // 내 앞사람이 도둑맞았는데 여벌있으면 앞사람
    
    // 1번부터 n번까지 체육복갯수
    vector<int> origin(n,1);
    
    // 도둑맞음
    for(int i=0;i<lost.size();i++){
        origin[lost[i]-1]--;
    }
    // 여벌
    for(int i=0;i<reserve.size();i++){
        origin[reserve[i]-1]++;
    }
    
    // 뒷사람 빌려줘
    for(int i=0;i<origin.size()-1;i++){
        if(origin[i]==2 && origin[i+1]==0){
            origin[i]--;
            origin[i+1]++;
        }
    }
    
    // 앞사람 빌려줘
    for(int i=1;i<origin.size();i++){
        if(origin[i]==2 && origin[i-1]==0){
            origin[i]--;
            origin[i-1]++;
        }
    }
    
    // 옷없으면 나가
    for(int i=0;i<origin.size();i++){
        if(origin[i]>0){
            answer1++;
        }
    }
    
    // 1번부터 n번까지 체육복갯수
    vector<int> origin2(n,1);
    
    // 도둑맞음
    for(int i=0;i<lost.size();i++){
        origin2[lost[i]-1]--;
    }
    // 여벌
    for(int i=0;i<reserve.size();i++){
        origin2[reserve[i]-1]++;
    }
    
    // 앞사람 빌려줘
    for(int i=1;i<origin2.size();i++){
        if(origin2[i]==2 && origin2[i-1]==0){
            origin2[i]--;
            origin2[i-1]++;
        }
    }
    
    // 뒷사람 빌려줘
    for(int i=0;i<origin2.size()-1;i++){
        if(origin2[i]==2 && origin2[i+1]==0){
            origin2[i]--;
            origin2[i+1]++;
        }
    }
    
    // 옷없으면 나가
    for(int i=0;i<origin2.size();i++){
        if(origin2[i]>0){
            answer2++;
        }
    }
    
    answer = max(answer1,answer2);
    
    return answer;
}