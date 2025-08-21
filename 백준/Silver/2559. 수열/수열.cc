#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; // 2~100,000
	int K; // 1~N
	cin >> N >> K;

	vector<int> temperatures(N + 1); // -100~100
	vector<int> prefixSum(N + 1, 0); // 누적합 배열

	for (int i = 1; i <= N; i++)
	{
		cin >> temperatures[i];
	}

	for (int i = 1; i <= K; i++)
	{
		prefixSum[1] += temperatures[i]; // 첫 K개의 온도 합
	}

	for (int i = 2; i <= N - K + 1; i++)
	{
		prefixSum[i] = prefixSum[i - 1] - temperatures[i - 1] + temperatures[i + K - 1]; // 슬라이딩 윈도우 방식으로 누적합 계산
	}

	auto maxIt = max_element(prefixSum.begin() + 1, prefixSum.begin() +N - K + 2); // 최대 누적합 찾기
	cout << *maxIt << '\n'; 
}