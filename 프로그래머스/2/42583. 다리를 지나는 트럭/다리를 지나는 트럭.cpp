#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int elapsedTime = 0;     // 경과 시간
    int weightSum = 0;       // 현재 다리 위 트럭들의 총 무게
    queue<int> bridge;       // 다리를 건너는 트럭을 나타내는 큐

    for (int i = 0; i < bridge_length; i++)
    {
        // 다리 길이만큼 0(빈 공간) 채우기
        bridge.push(0);
    }

    int truckIndex = 0;  // 현재 대기 중인 트럭의 인덱스
    while (truckIndex < truck_weights.size() || weightSum > 0) 
    {
        elapsedTime++;

        // 다리를 지난 트럭이 나오면 무게 감소
        weightSum -= bridge.front();
        bridge.pop();

        // 다음 트럭을 다리에 올릴 수 있는지 확인
        if (truckIndex < truck_weights.size() && weightSum + truck_weights[truckIndex] <= weight) 
        {
            bridge.push(truck_weights[truckIndex]);
            weightSum += truck_weights[truckIndex];
            truckIndex++;
        } 
        else 
        {
            bridge.push(0); // 트럭이 못 올라오면 빈 공간(0) 추가
        }
    }
    answer = elapsedTime;
    
    return answer;
}
