#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long x : numbers) 
    {
        if (x % 2 == 0) 
        {
            answer.push_back(x + 1); // 짝수는 +1
        } 
        else 
        {
            unsigned long long bit = 1; // 부호 없는 long long 사용
            while (x & bit) bit <<= 1; // 가장 낮은 0 찾기
            answer.push_back(x + bit - (bit >> 1)); // 비트 변환
        }
    }
    
    return answer;
}
