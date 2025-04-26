#include <iostream>

using namespace std;

int countSerialSum(const int& N)
{
    int count = 0;
    int start = 1, end = 1;
    int sum = 1;
    while(start<=N)
    {
        if(sum==N)
        {
            count++;
            sum-=start;
            start++;
        }
        else if(sum<N)
        {
            end++;
            sum+=end;
        }
        else// sum > N
        {
            sum-=start;
            start++;
        }
    }
    
    return count;
}

int main()
{
    int N;
    cin>>N;
    cout<<countSerialSum(N);
    return 0;
}