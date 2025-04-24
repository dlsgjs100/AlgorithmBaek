#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int blackJack(const vector<int>& cards, const int& M)
{
    int count = cards.size();
    int maxSum = 0;
    
    for(int i=0;i<count-2;i++)
    {
        for(int j=i+1;j<count-1;j++)
        {
            for(int k = j+1;k<count;k++)
            {
                int sum = cards[i] + cards[j] + cards[k];
                
                if(sum<=M)
                {
                    maxSum = max(maxSum,sum);
                    if(maxSum==M)
                    {
                        return maxSum;
                    }
                }
            }
        }
    }
    return maxSum;
}
int main()
{
    int N,M;
    cin >> N >> M;
    
    vector<int> cards(N); 
    for(int i=0;i<N;i++)
    {
        cin >> cards[i];
    }
    cout<<blackJack(cards,M);
    return 0;
}