#include <iostream>

using namespace std;

int round(int a, int b){
    int count=0;
    while(a!=b){
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        count++;
    }
    return count;
}

int solution(int n, int a, int b)
{
    int answer = 0;
    // 한 명이 남을 때까지 토너먼트
    // A번은 B번과 몇 번째 라운드에서 만나나
    // 서로 붙기 전까지 항상 이긴다.
    // N : 게임 참가자 수 (2의 지수승 => 부전승 X)
    // A : 참가자 번호
    // B : 경쟁자 번호
    // return 만나는 라운드
    
    answer = round(a,b);
    cout<<answer;
    
    return answer;
}