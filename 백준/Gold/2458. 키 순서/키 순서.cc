#include <iostream>
using namespace std;

bool graph[501][501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; // 2~500
	int M; // 0~N(N-1)/2
	cin >> N >> M;

	while (M--)
	{
		int a, b; // 1~N
		cin >> a >> b; // a<b
		graph[a][b] = true;
	}

	// 플로이드-워셜 알고리즘
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (graph[i][k] && graph[k][j])
				{
					// i에서 k를 거쳐 j로 가는 경로가 있다면 i에서 j로 가는 경로도 있다
					graph[i][j] = true;
				}
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= N; i++)
	{
		int count = 0;
		for (int j = 1; j <= N; j++)
		{
			if(graph[i][j] || graph[j][i])
			{
				count++; // i와 j가 연결되어 있거나, j와 i가 연결되어 있다면 count 증가
			}
		}
			
		// i와 연결된 정점이 N-1개라면[자신의 키가 몇 번째인지 알 수 있다면] result 증가
		if (count == N - 1)
		{
			result++; 
		}
	}

	cout << result << '\n'; 
	return 0;
}