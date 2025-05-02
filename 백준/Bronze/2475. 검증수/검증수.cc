#include <iostream>
#include <vector>

using namespace std;

// 6자리 고유번호 00000ㅁ ~ 99999ㅁ
// ㅁ : 검증수 = 처음 5자리 각 숫자의 제곱의 합을 10으로 나눈 나머지  
int main()
{
    vector<int> numbers;
    
    for(int i=0;i<5;i++)
    {
        int num;
        cin>>num;
        numbers.push_back(num);
    }
    int checkingNumber;
    int sum = 0;
    for(const int& number : numbers)
    {
        sum += number*number;
    }
    checkingNumber = sum%10;
    cout<<checkingNumber;
    return 0;
}