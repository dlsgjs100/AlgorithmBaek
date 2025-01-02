#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){ 
  return a > b; 
} 

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int boxCount=score.size() / m;
    // 사과의 개수가 m개가 될때까지 점수가 제일 높은 사과부터 담고 
    // 이 과정을 score의 size / m 번
    // 이익이 발생하지 않으면 0을 return
    
    // 내림차순, m개씩 끊어서 담기
    sort(score.begin(),score.end(),desc);
                
    for(int i=0;i<boxCount;i++){
        vector<int> box;
        
        for(int j=i * m ;j < (i+1) * m;j++){
            box.push_back(score[j]);
        }
        answer+=box[m-1] * m;
    }
    
    return answer;
}