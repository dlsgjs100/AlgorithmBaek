#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPrime(long long n)
{
    if(n <= 1)
    {
        return false;
    }
    for(long long i = 2; i * i <= n; i++)  
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void countConvertToKPrime(int n, int k, int& answer)
{
    vector<int> num;
    while(n>0)
    {
        num.push_back(n%k);
        n/=k;
    }
    long long tempNum=0;
    for(int i=num.size()-1;i>=0;i--)
    {
        if(num[i]!=0)
        {
            tempNum = 10 * tempNum + num[i];
        }
        else if(tempNum>0)
        {
            if (isPrime(tempNum)) 
            {
                answer++;
            }
            tempNum = 0;
        }
    }
    
    if (tempNum > 0 && isPrime(tempNum)) {
        cout<<tempNum;
        answer++;
    }
}

int solution(int n, int k) {
    int answer = 0;
    countConvertToKPrime(n,k,answer);
    return answer;
}