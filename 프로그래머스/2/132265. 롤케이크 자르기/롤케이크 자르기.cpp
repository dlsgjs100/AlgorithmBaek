#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    // 토핑을 두 조각으로 나눈다.
    // 토핑의 가짓수를 센다.
    // 각 조각의 토핑 가짓수가 일치하면 공평하다.
    unordered_map<int,int> top1;
    unordered_map<int,int> top2;
    
    for(int top:topping)
    {
        top1[top]++;
    }
    
    int count = top1.size();
    
    for(int i=0;i<topping.size()-1;i++)
    {
        int top = topping[i];
        
        top2[top]++;
        top1[top]--;
        if(top1[top]==0)
        {
            count--;
        }
        
        if(count==top2.size())
        {
            answer++;
        }
    }
    
    return answer;
}