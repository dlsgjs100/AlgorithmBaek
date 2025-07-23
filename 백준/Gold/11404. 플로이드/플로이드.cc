#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> minCost(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= n; ++i)
	{
		minCost[i][i] = 0;
	}

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		minCost[a][b] = min(minCost[a][b], c); // 중복 간선 고려
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (minCost[i][j] > minCost[i][k] + minCost[k][j])
				{
					minCost[i][j] = minCost[i][k] + minCost[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (minCost[i][j] == INF)
			{
				cout << "0 ";
			}
			else
			{
				cout << minCost[i][j] << " ";
			}
		}
		cout << '\n';
	}
	return 0;
}