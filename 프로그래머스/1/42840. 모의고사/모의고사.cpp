#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // n번째 문제인지 알면 채점가능
    // 가장 많은 문제를 맞힌 사람 => 각자 몇문제 맞췄는지 세야함
    int count1=0;
    int count2=0;
    int count3=0;
    
    
    for(int i=0;i<answers.size();i++){
    // 1번 방식 : i%5+1
        if(answers[i]==i%5+1){
            count1++;
        }
        
    // 2번 방식 : 2 1 2 3 2 4 2 5 => 짝수번째 2 
        if(i%2==0 && answers[i]==2){
            count2++;
        }
        else if(i%8==1 && answers[i]==1){
            count2++;
        }
        else if(i%8==3 && answers[i]==3){
            count2++;
        }
        else if(i%8==5 && answers[i]==4){
            count2++;
        }
        else if(i%8==7 && answers[i]==5){
            count2++;
        }
        
    // 3번 방식 : 33 11 22 44 55 
        if((answers[i]==1||answers[i]==2) && i%10/2==answers[i])
        {
            count3++;
        }
        else if(i%10/2==0 && answers[i]==3){
            count3++;
        }
        else if(i%10/2==3 && answers[i]==4){
            count3++;
        }
        else if(i%10/2==4 && answers[i]==5){
            count3++;
        }
    }
    
    int maxcount = max({count1,count2,count3});
    if(count1==maxcount){
        answer.push_back(1);
    }
    if(count2==maxcount){
        answer.push_back(2);
    }
    if(count3==maxcount){
        answer.push_back(3);
    }
    
    return answer;
}