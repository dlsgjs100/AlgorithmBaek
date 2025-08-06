#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> scores(N + 1);
    for (int i = 1; i <= N; i++) 
    {
        cin >> scores[i];
    }

    vector<int> dp(N + 1, 0);
    dp[1] = scores[1];

    if (N >= 2)
    {
        dp[2] = scores[1] + scores[2];
    }

    for (int i = 3; i <= N; i++) 
    {
        dp[i] = max(dp[i - 2] + scores[i], dp[i - 3] + scores[i - 1] + scores[i]);
    }

    cout << dp[N] << '\n';
    return 0;
}