#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	int height = triangle.size();
	vector<vector<int>> dp(height, vector<int>(height, 0));
	dp[0][0] = triangle[0][0]; // 첫 번째 줄의 첫 번째 원소 초기화

	for (int i = 1; i < height; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + triangle[i][j]; // 왼쪽 경계
			}
			else if(j == i)
			{
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j]; // 오른쪽 경계
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]; // 중간 부분
			}
		}
	}

	// 마지막 줄에서 최대값 찾기
	for (int i = 0; i < height; i++)
	{
		answer = max(answer, dp[height - 1][i]);
	}

	return answer;
}