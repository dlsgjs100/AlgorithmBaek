#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    // 카드1 카드2 
    // 골을 순회하는 인덱스, 카드1이나 카드2의 인덱스의 합
    int index1=0;
    int index2=0;
    int indexGoal;
    
    for(indexGoal = 0; indexGoal<goal.size();indexGoal++){
        if(goal[indexGoal]==cards1[index1]){
            index1++;
        }
        else if(goal[indexGoal]==cards2[index2]){
            index2++;
        }
        else{
            answer = "No";
            return answer;
        }
    }
    
    answer = "Yes";
    
    return answer;
}

