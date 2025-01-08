#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int solution(vector<int> arr) {
    int answer = 0;
    // 0번째와 1번째의 최소공배수를 구함
    // 2번째와의 최소공배수를 구함
    // n번째까지 반복
    int size = arr.size();
    // 최소공배수를 담을 컨테이너
    vector<int> lcmVec;
    lcmVec.push_back(lcm(arr[0],arr[1]));// 0번째와 1번째의 최소공배수가 0번에 저장
    for(int i=0;i<size-2;i++){
        lcmVec.push_back(lcm(lcmVec[i],arr[i+2]));
        // 0번최소공배수와 2번째의 최소공배수를 1번에 저장
        // 1번최소공배수와 3번째의 최소공배수를 2번에 저장
    }
    
    // 최소공배수들의 개수는 arr의 원소의 개수-1
    // => 마지막 최소공배수의 위치 : arr의 원소의 개수 - 1 - 1
    answer = lcmVec[size-2];
    
    return answer;
}