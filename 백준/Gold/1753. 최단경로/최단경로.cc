#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int V, E; // V: 정점 수, E: 간선 수
	cin >> V >> E;

	int K; // 시작 정점
	cin >> K;

	const int INF = 1e9; // 도달 불가능한 경우 사용할 무한대 값 (충분히 큰 수)

	// 인접 리스트(adj[u] = (v, w)): u에서 v로 가는 가중치 w인 간선 저장
	vector<vector<pair<int, int>>> adj(V + 1);

	// 시작점 K에서 각 정점까지의 최단 거리 저장 배열, 처음엔 모두 INF로 초기화
	vector<int> dist(V + 1, INF);
	dist[K] = 0; // 시작점은 자기 자신까지 거리 0

	// 간선 정보 입력 받기
	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w); // u에서 v로 가는 가중치 w인 간선 추가
	}

	// 최소 힙을 위한 우선순위 큐: (거리, 정점)
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, K); // 시작점 추가

	// 다익스트라 알고리즘 시작
	while (!pq.empty())
	{
		// 현재 가장 가까운 정점 꺼내기
		pair<int, int> top = pq.top();
		pq.pop();
		int curDist = top.first; // 현재까지 누적 거리
		int u = top.second;      // 현재 정점

		// 이미 더 짧은 경로로 방문한 적이 있다면 무시
		if (curDist > dist[u])
		{
			continue;
		}

		// 인접한 모든 정점 확인
		for (const auto& edge : adj[u])
		{
			int v = edge.first;   // 인접 정점
			int w = edge.second;  // u에서 v로 가는 간선의 가중치

			// 더 짧은 경로를 찾은 경우 갱신
			if (dist[v] > curDist + w)
			{
				dist[v] = curDist + w;
				pq.emplace(dist[v], v); // 우선순위 큐에 갱신된 정점 추가
			}
		}
	}

	// 결과 출력
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
		{
			cout << "INF\n"; // 도달 불가능한 경우
		}
		else
		{
			cout << dist[i] << '\n'; // 최단 거리 출력
		}
	}

	return 0;
}
