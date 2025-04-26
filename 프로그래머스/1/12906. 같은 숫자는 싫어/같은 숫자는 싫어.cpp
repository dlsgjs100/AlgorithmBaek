#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> recentInteger;
    
    answer.push_back(arr[0]); // 첫 원소는 연속X
    // 스택에 최근 원소를 저장해 같은 경우는 지나가고 다를 경우에만 배열에 저장후 스택에 추가
    recentInteger.push(arr[0]);
    for(const int& num : arr)
    {
        if(num != recentInteger.top())
        {
            answer.push_back(num);
            recentInteger.push(num);
        }
    }
    return answer;
}