#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    // return 만들어진 1차원 배열
    
    // 이차원 배열을 만들어 해결하면 시간제한 위험
    // 1 2 3 4
    // 2 2 3 4
    // 3 3 3 4
    // 4 4 4 4
    
    // index를 n으로 나눈 나머지 배열
    // 0 1 2 3
    // 0 1 2 3
    // 0 1 2 3
    // 0 1 2 3
    
    // index를 n으로 나눈 몫 배열
    // 0 0 0 0
    // 1 1 1 1
    // 2 2 2 2
    // 3 3 3 3
    // arr[index]의 원소는 index/n 과 index%n중 큰 값 + 1
    
    for(long long i=left;i<=right;i++){
        long long num = i/n>i%n ? i/n + 1: i%n + 1;
        answer.push_back(num);
    }
    
    return answer;
}