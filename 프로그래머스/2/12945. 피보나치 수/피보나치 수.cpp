#include <string>
#include <vector>

using namespace std;

int fibonacciBottomUp(int n) {
    if (n == 0) return 0; // 기본 값
    if (n == 1) return 1; // 기본 값
    
    vector<int> dp(n + 1);
    dp[0] = 0; // 초기 값
    dp[1] = 1; // 초기 값
    
    // F(0) = 0, F(1) = 1일 때, 1 이상의 n에 대하여 F(n) = F(n-1) + F(n-2)
    // 반복문으로 계산
    for (int i = 2; i <= n; i++) {
        // (a + b) % m = ((a % m) + (b % m)) % m
        dp[i] = (dp[i - 1]%1234567 + dp[i - 2]%1234567)%1234567;
    }
    return dp[n];
}

int solution(int n) {
    int answer = 0;
    answer =  fibonacciBottomUp(n);
    return answer;
}