#include <string>
#include <vector>

using namespace std;

void findTargetNumber(const vector<int>& numbers,const int& target, int sum, int index, int& answer)
{
    if(index == numbers.size())
    {
        if(sum == target)
        {
            answer++;
        }
        return;
    }
    
    findTargetNumber(numbers, target, sum+numbers[index],index+1,answer);
    findTargetNumber(numbers, target, sum-numbers[index],index+1,answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    findTargetNumber(numbers, target, 0,0,answer);
    return answer;
}