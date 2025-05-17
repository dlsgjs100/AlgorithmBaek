#include <iostream>
#include <queue>

using namespace std;

struct absCompare
{
	bool operator()(const int& a, const int& b)
	{
		// 절댓값이 같으면 값이 더 작은 게 우선
		if (abs(a) == abs(b))
		{
			return a > b; 
		}
		// 절댓값이 더 작은 게 우선
		return abs(a) > abs(b); 
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;//1~100000
	cin >> N;
	// 기본적으로 최대힙
	priority_queue<int, vector<int>, absCompare> absHeap;
	while (N--)
	{
		int x; // int범위
		cin >> x;
		if (x != 0)
		{
			absHeap.push(x);
			// 배열에 x라는 값을 넣는 연산
		}
		else
		{
			if (absHeap.empty())
			{
				// 배열이 비어있는데 출력하라고 하면 0 출력
				cout << 0 << '\n';
			}
			else
			{
				// 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거
				// 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거
				cout << absHeap.top() << '\n';
				absHeap.pop();
			}
		}
	}

	return 0;
}