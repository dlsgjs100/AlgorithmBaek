#include <iostream>

using namespace std;

// -뒤에 +인 경우 +를 괄호로 묶는다
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string expression;
    cin>>expression;
    
    int result = 0;
    int currentNum = 0;
    bool isNegative = false;
    for(char c : expression)
    {
        if(isdigit(c))
        {
            currentNum = currentNum*10 + (c-'0');
        }
        else if(c=='+')
        {
            if(isNegative)
            {
                result-=currentNum;
            }
            else
            {
                result+=currentNum;
            }
            currentNum = 0;
        }
        else if (c == '-')
        {
            if (isNegative)
            {
                result -= currentNum;
            }
            else
            {
                result += currentNum;
            }
            currentNum = 0;
            isNegative = true; // 다음 숫자는 음수로 처리
        }
    }
    if (isNegative)
    {
        result -= currentNum;
    }
    else
    {
        result += currentNum;
    }
    cout << result << '\n';
    return 0;
}