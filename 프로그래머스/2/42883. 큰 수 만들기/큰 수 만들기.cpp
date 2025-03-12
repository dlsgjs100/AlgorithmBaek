#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    stack<char> s;
    
    for (char digit : number) 
    {
        // 스택이 비어 있지 않고, k가 남아 있으며, 스택의 top보다 현재 숫자가 크면 제거
        while (!s.empty() && k > 0 && s.top() < digit) 
        {
            s.pop();
            k--;
        }
        s.push(digit); // 현재 숫자를 스택에 추가
    }

    // 아직 k개의 숫자를 다 제거하지 못했다면 뒤에서 삭제
    while (k > 0) 
    {
        s.pop();
        k--;
    }

    // 스택을 문자열로 변환
    while (!s.empty()) 
    {
        answer = s.top() + answer;
        s.pop();
    }

    return answer;
}
