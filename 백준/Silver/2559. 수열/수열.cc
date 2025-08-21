#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	vector<int> temperatures(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> temperatures[i];
	}

	int window = 0;
	for (int i = 1; i <= K; i++)
	{
		window += temperatures[i];
	}
	int maxSum = window;

	for (int i = K + 1; i <= N; i++)
	{
		window += temperatures[i] - temperatures[i - K];
		if (window > maxSum)
		{
			maxSum = window;
		}
	}
	cout << maxSum << '\n';
}