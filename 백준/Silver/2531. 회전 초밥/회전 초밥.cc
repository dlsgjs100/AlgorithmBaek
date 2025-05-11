#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
	int N, d, k, c;// 2~30000, 2~3000, 2~3000, 1~d
	cin >> N >> d >> k >> c;

	vector<int> sushi(N);
	for (int i = 0; i < N; i++)
	{
		cin >> sushi[i];
	}

	// 슬라이딩 윈도우를 사용, 각 번호의 초밥의 개수를 저장
	vector<int> count(d + 1, 0); // 초밥 번호는 1~d
	int kind = 0;

	// 초기 윈도우
	// 초밥 k개를 먹을 때 처음 넣는 것이라면 종류 ++
	for (int i = 0; i < k; i++)
	{
		if (count[sushi[i]] == 0)
		{
			kind++;
		}
		count[sushi[i]]++;
	}

	int maxKind = kind;
	// 회전 벨트를 고려한 슬라이딩 윈도우
	for (int i = 1; i <= N; i++)
	{
		// 윈도우에서 하나 제거
		int removeIdx = sushi[(i - 1) % N];
		count[removeIdx]--;
		if (count[removeIdx] == 0)
		{
			kind--;
		}

		// 윈도우에 하나 추가
		int addIdx = sushi[(i - 1 + k) % N];
		if (count[addIdx] == 0)
		{
			kind++;
		}
		count[addIdx]++;

		// 쿠폰 초밥 추가
		// 윈도우에 쿠폰 초밥이 없다면 +1;
		int tempKind = kind;
		if (count[c] == 0)
		{
			tempKind++;
		}

		maxKind = max(maxKind, tempKind);
	}

	cout << maxKind << '\n';
	return 0;
}