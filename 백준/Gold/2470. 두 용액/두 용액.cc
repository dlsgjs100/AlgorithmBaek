#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; // 2~100000 용액의 수
	cin >> N;
	vector<int> values;
	for (int i = 0; i < N; i++)
	{
		int value;
		cin >> value;
		values.push_back(value);
	}
	sort(values.begin(), values.end());

	// 투포인터로 처음과 끝에서 더해가며 절대값의 최소값을 찾는다.
	int start, end, index1, index2, minValue;
	start = 0;
	end = values.size() - 1;
	minValue = INT_MAX;
	while (start < end)
	{
		int sum = 0;
		sum = values[start] + values[end];
		// 최소값 갱신
		if (abs(sum) < minValue)
		{
			minValue = abs(sum);
			index1 = start;
			index2 = end;
		}
		if (sum < 0)
		{
			start++;
		}
		else if (sum > 0)
		{
			end--;
		}
		else
		{
			break; // 0이 나왔으므로 더 이상 탐색할 필요 없음
		}
	}
	vector<int> result;
	result.push_back(values[index1]);
	result.push_back(values[index2]);
	cout << result[0] << " " << result[1] << '\n';
	return 0;
}