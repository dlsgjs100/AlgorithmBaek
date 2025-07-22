#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; // 1~1000
	cin >> N;
	int M; // 1~100,000
	cin >> M;

	vector<vector<pair<int, int>>> busInfo(N + 1); // 시작 도시, 도착 도시, 비용

	while (M--)
	{
		int startCity, endCity, busCost; // 1~N, 1~N, 1~100,000
		cin >> startCity >> endCity >> busCost;
		busInfo[startCity].emplace_back(endCity, busCost);
	}

	int A, B; // 1~N, 1~N
	cin >> A >> B; // A: 시작 도시, B: 도착 도시

	// 다익스트라 알고리즘을 위한 우선순위 큐 (비용, 도시)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, A); // 시작 도시 A에서 비용 0으로 시작

	vector<int> minCost(N + 1, 1e9); // 각 도시까지의 최소 비용을 저장
	minCost[A] = 0; // 시작 도시 A의 비용은 0

	while (!pq.empty())
	{
		// 현재 가장 적은 비용 도시 꺼내기
		pair<int, int> top = pq.top();
		pq.pop();
		int currentCost = top.first; // 현재까지의 비용
		int currentCity = top.second; // 현재 도시

		if(currentCity == B) // 도착 도시 B에 도달하면 종료
		{
			cout << currentCost << '\n'; // 최소 비용 출력
			return 0;
		}

		// 이미 더 적은 비용으로 방문한 도시라면 무시
		if (currentCost > minCost[currentCity])
		{
			continue;
		}

		// 현재 도시에서 연결된 모든 버스 정보 확인
		for(const auto& bus : busInfo[currentCity])
		{
			int nextCity = bus.first; // 다음 도시
			int nextCost = bus.second; // 현재 도시에서 다음 도시까지의 비용
			// 다음 도시까지의 새로운 비용 계산
			int newCost = currentCost + nextCost;
			// 더 적은 비용으로 다음 도시를 방문할 수 있다면 갱신
			if (newCost < minCost[nextCity])
			{
				minCost[nextCity] = newCost;
				pq.emplace(newCost, nextCity); // 우선순위 큐에 추가
			}
		}
	}

	return 0;
}