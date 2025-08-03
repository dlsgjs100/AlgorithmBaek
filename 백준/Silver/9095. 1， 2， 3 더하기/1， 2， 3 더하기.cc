#include <iostream>
using namespace std;

int dp[12]; 

int countWays(int n)
{
	if (n < 0) return 0;
	if (n == 0) return 1;

	if (dp[n] != 0) return dp[n];

	return dp[n] = countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;
		cout << countWays(n) << '\n';
	}

	return 0;
}
