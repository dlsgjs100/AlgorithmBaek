#include <vector>
#include <climits>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int left = 0;
    int right = 0;
    int sum = sequence[0];
    int minLength = INT_MAX;
    vector<int> answer(2, -1);

    while (right < sequence.size()) 
    {
        if (sum < k) 
        { 
            // 합이 부족하면 right 이동
            right++;
            if (right < sequence.size()) 
            {
                sum += sequence[right];
            }
        } 
        else if (sum > k) 
        { 
            // 합이 초과하면 left 이동
            sum -= sequence[left];
            left++;
        } 
        else 
        { 
            // 정확히 k일 때, 최소 길이 비교
            if (right - left < minLength) 
            {
                minLength = right - left;
                answer[0] = left;
                answer[1] = right;
            }
            sum -= sequence[left];
            left++;
        }
    }
    
    return answer;
}
