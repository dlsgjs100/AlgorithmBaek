#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long numLong = num;
    int answer = 0;
    int count=0;//시행횟수
    
    do{
        if((numLong==1)&&(count==0)){
            answer = 0;
            return answer;
            break;
        }
        else if((numLong==1)&&(count!=1)){
            answer = count;
            return answer;
            break;
        }
        if(numLong%2==0){
            numLong/=2;
            }
        else{
            numLong=numLong*3+1;
            }
        count++;
    }while(count<=500);
    
    
    return -1;
}