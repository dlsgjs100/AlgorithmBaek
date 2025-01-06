#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count=0;
    int count0=0;
    // lottos와 win_nums를 비교해서 일치하는 개수
    // 최고 - lottos의 0들이 전부 win_nums의 다른수와 일치하면
    // 최저 - lottos의 0들이 전부 win_nums의 다른수와 불일치하면
    
    // 비교는 win_nums를 순회하면서 lottos의 원소와 일치하는지
    // 일치하면 break
    for(int i=0;i<lottos.size();i++){
        for(int j=0;j<win_nums.size();j++){
            if(win_nums[j]==lottos[i]){
                count++;
                break;
            }
        }
        if(lottos[i]==0){
            count0++;
        }
    }    
    
    int best_rank = (count + count0 >= 2) ? 7 - (count + count0) : 6;
    int worst_rank = (count >= 2) ? 7 - count : 6;

    answer.push_back(best_rank);
    answer.push_back(worst_rank);
    
    return answer;
}