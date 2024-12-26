#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    int digit = 0; // 자릿수
    long long num = n;
    
    // n은 digit자리수 정수
    do{
        num/=10;
        digit++;
    }while(num>0);

    // 각 자릿수의 숫자를 벡터형으로
    vector<long long> v(digit);
    for(int i=0;i<digit;i++){
        v[i] = n%10;
        n/=10;
    }
    
    // 내림차순으로 정렬 (0번째 원소부터 나머지와 비교해 작거나 같으면 스왑)
    for(int i=0;i<digit;i++){
        for(int j=i;j<digit;j++){
            if(v[i]<=v[j]){
                swap(v[i],v[j]);
            }
        }
    }
    
    // 벡터를 다시 정수로 변환
    for(int i=0;i<digit;i++){
        long long temp = 1;
        for(int j=i;j<digit-1;j++){
            temp *= 10;
        }
        answer += v[i] * temp;
    }
    
    return answer;
}