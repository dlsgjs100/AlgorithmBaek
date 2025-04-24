#include <iostream>
#include <vector>

using namespace std;

int blackJack(const vector<int>& cards , const int& M)
{
    // 세장을 골라 합을 모두 구해 M보다 작거나 같으면서 최대값을 반환
    int count = cards.size();
    int maxSum = 0;
    // 5
    // 123 124 125 134 135 145 234 235 245 345
    for(int i=0;i<count-2;i++)
    {
        for(int j=i+1;j<count-1;j++)
        {
            for(int k=j+1;k<count;k++)
            {
                int sum = cards[i] + cards[j] + cards[k];
                if(sum<=M && sum >=maxSum)
                {
                    maxSum = sum;
                }
            }
        }
    }
    return maxSum;
}

int main()
{
    int N=0;
    int M=0;
    cin>>N;
    cin>>M;
    
    vector<int> cards;
    for(int i=0;i<N;i++)
    {
        int num=0;
        cin>>num;
        cards.push_back(num);
    }
    int answer = blackJack(cards,M);
    cout<<answer;
    return 0;
}