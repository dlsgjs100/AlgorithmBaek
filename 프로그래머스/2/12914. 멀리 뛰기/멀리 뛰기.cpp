#include <string>
#include <vector>

using namespace std;

const int MOD = 1234567;

long long solution(int n) {
    long long answer = 0;
    // 조합으로 풀면 오버플로우 발생가능
    // 맨 끝에 도달하는 방법 -> 2칸 or 1칸
    // 이전칸에 도달하는 방법 -> 2칸 or 1칸
    // dp사용
    vector<long long> dp(n,0);
   
    dp[0]=1; // 1칸일때 방법의 수
    dp[1]=2; // 2칸일때 방법의 수
    for(int i=2;i<n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) %MOD;
    }
    answer = dp[n-1];
    return answer;
}