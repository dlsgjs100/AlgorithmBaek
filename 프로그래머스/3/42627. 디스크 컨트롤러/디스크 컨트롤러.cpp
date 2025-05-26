#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 대기큐 : 작업의 번호, 작업의 요청 시각, 작업의 소요 시간
// 소요시간이 짧을수록, 요청시각이 빠를수록, 번호가 작을수록 우선순위
// 한 번에 하나의 작업만 수행 작업을 마칠 때까지 그 작업만 수행
// 마치는 시점과 요청이 들어오는 시점이 겹치면 작업을 마치자마자 요청이 들어온 작업을 저장
// 우선순위가 높은 작업을 꺼내 작업 이때 걸리는 시간은 없다
// 반환 시간은 작업종료시각-요청시각
// return 모든 요청 작업의 반환시간의 평균의 정수부분 
// 각 작업은 [요청시각,소요시간]으로 주어짐

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    // 요청 시각 기준 정렬
    sort(jobs.begin(), jobs.end());

    int currentTime = 0;
    int totalTime = 0;
    int index = 0;
    int count = 0;

    // 우선순위 큐 (소요 시간 기준)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    while (count < jobs.size()) 
    {
        // 현재 시간까지 요청된 작업 큐에 삽입
        while (index < jobs.size() && jobs[index][0] <= currentTime) 
        {
            pq.emplace(jobs[index][1], jobs[index][0]); // (소요시간, 요청시간)
            index++;
        }

        if (!pq.empty()) 
        {
            auto [duration, startTime] = pq.top();
            pq.pop();

            currentTime += duration;
            totalTime += (currentTime - startTime);
            count++;
        }
        else 
        {
            // 대기할 작업이 없으면 다음 요청까지 점프
            currentTime = jobs[index][0];
        }
    }
    answer = totalTime / jobs.size(); // 평균 반환시간의 정수 부분
    return answer;
}