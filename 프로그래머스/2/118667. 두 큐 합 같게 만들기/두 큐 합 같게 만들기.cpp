#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> q1, q2;
    long long sum1 = 0, sum2 = 0;
    
    for (int num : queue1) 
    {
        q1.push(num);
        sum1 += num;
    }
    for (int num : queue2) 
    {
        q2.push(num);
        sum2 += num;
    }
    
    int count = 0;
    int maxCount = (queue1.size() + queue2.size()) * 2;

    while (sum1 != sum2 && count <= maxCount) 
    {
        if (sum1 > sum2) 
        {
            int x = q1.front();
            q1.pop();
            q2.push(x);
            sum1 -= x;
            sum2 += x;
        } 
        else 
        {
            int x = q2.front();
            q2.pop();
            q1.push(x);
            sum2 -= x;
            sum1 += x;
        }
        count++;
    }
    
    if (sum1 == sum2)
    {
        return count;
    }
    else
    {
        return -1;
    }
}
