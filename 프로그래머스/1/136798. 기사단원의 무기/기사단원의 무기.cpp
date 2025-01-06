#include <string>
#include <vector>
#include <cmath>

using namespace std;

int Count(int i, int limit, int power){
    int count=0;
    for(int j=1;j<=sqrt(i);j++){
        if(i%j==0){
            if(i==j*j){
            count++;
                }
            else{
                count+=2;
            }
        }
    }
    if(count>limit){
        count=power;
        }
    return count;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    // 1부터 number의 약수의 개수의 합
    // 단 limit보다 크면 power로 대체됨
    
    for(int i=1;i<=number;i++){
            answer += Count(i, limit, power);
    }
    
    return answer;
}