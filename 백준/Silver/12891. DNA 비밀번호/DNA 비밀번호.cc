#include <iostream>
#include <string>
#include <vector>

using namespace std;

int charToIndex(char c)
{
	if (c == 'A')
	{
		return 0;
	}
	if (c == 'C')
	{
		return 1;
	}
	if (c == 'G')
	{
		return 2;
	}
	if (c == 'T')
	{
		return 3;
	}
	return -1; // 이론상 도달하지 않음
}

bool isValid(const vector<int>& currentCount, const vector<int>& minCount)
{
	for (int i = 0; i < 4; i++)
	{
		if (currentCount[i] < minCount[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int S, P;
	cin >> S >> P;
	string DNA;
	cin >> DNA;

	vector<int> minCount(4); // A, C, G, T 최소 조건
	for (int i = 0; i < 4; i++)
	{
		cin >> minCount[i];
	}

	vector<int> currentCount(4); // 현재 슬라이딩 윈도우의 ACGT 개수

	// 초기 윈도우
	for (int i = 0; i < P; i++)
	{
		currentCount[charToIndex(DNA[i])]++;
	}

	int count = 0;
	if (isValid(currentCount, minCount))
	{
		count++;
	}

	// 슬라이딩 윈도우
	for (int i = P; i < S; i++)
	{
		currentCount[charToIndex(DNA[i - P])]--; // 왼쪽 문자 제거
		currentCount[charToIndex(DNA[i])]++;     // 오른쪽 문자 추가
		if (isValid(currentCount, minCount))
		{
			count++;
		}
	}

	cout << count;
	return 0;
}
