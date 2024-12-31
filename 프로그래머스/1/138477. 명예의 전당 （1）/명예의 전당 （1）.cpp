#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    // 10
    // 10 100
    // 10 100 20 => 10 20 100
    // 10 100 20 150 => 10 20 100 150
    // 10 100 20 150 1 => 1 10 20 100 150
    
    // 전당의 길이가 k보다 작으면 받은 뒤 오름차순으로 정렬해 첫 번째 원소
    // 전당의 길이가 k보다 크거나 같으면 오름차순으로 정렬한 첫 번째 원소보다 크면 받고 오름차순으로 정렬후 첫번째 원소 삭제, 작으면 첫번째 원소
    // score의 원소의 갯수만큼 시행
    
    int count = score.size();
    vector<int> temp;
    
    for(int i=0;i<count;i++){
        if(temp.size()<k){
            temp.push_back(score[i]);
            sort(temp.begin(),temp.end());
            answer.push_back(temp[0]);
        }
        else{
            if(score[i]>=temp[0]){
                temp.push_back(score[i]);
                sort(temp.begin(),temp.end());
                temp.erase(temp.begin());
                answer.push_back(temp[0]);
            }
            else{
                answer.push_back(temp[0]);
            }
        }
    }
    
    
    
    return answer;
}