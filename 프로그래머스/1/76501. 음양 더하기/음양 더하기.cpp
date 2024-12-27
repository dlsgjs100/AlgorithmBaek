#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 123456789;
    int size=absolutes.size();
    int positive=0;
    int negative=0;
    
    for(int i=0;i<size;i++){
        if(signs[i]){
            positive += absolutes[i];
        }
        else{
            negative+=absolutes[i];
        }
    }
    
    answer = positive - negative;
    
    return answer;
}