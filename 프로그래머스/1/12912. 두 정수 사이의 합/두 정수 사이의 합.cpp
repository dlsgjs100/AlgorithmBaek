#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    //작은 수에서부터 1씩 증가하면서 더해나간다.
    //큰수보다 작거나 같을때 반복
    //변수의 타입을 long long타입으로 맞추어 오버플로우를 방지한다.
    long long sum=0;
    long long temp=0; 
    
    // 대소관계에 따른 분류
    if(a>b){
        temp = b;
        do{
            sum+=temp;
            temp++;
        }while(temp<=a);
        
        answer = sum;
    }
    else if(a<b){
        temp = a;
        do{
            sum+=temp;
            temp++;
        }while(temp<=b);
        
        answer = sum;
    }
    else{
        answer = a;
    }
    
    return answer;
}