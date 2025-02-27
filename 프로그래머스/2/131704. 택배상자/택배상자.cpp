#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> mainContainer;  // 메인 컨테이너 (FIFO)
    stack<int> subContainer;   // 보조 컨테이너 (LIFO)
    
    int index = order.size();
    for (int i = 1; i <= index; i++) {
        mainContainer.push(i);
    }

    int orderIdx = 0;  // 현재 order에서 처리해야 할 인덱스

    while (!mainContainer.empty() || !subContainer.empty()) 
    {
        // 메인 컨테이너에서 order[orderIdx]와 같은 박스를 바로 실을 수 있는 경우
        if (!mainContainer.empty() && mainContainer.front() == order[orderIdx]) 
        {
            mainContainer.pop();
            answer++;
            orderIdx++;
        }
        // 보조 컨테이너에서 order[orderIdx]와 같은 박스를 실을 수 있는 경우
        else if (!subContainer.empty() && subContainer.top() == order[orderIdx]) 
        {
            subContainer.pop();
            answer++;
            orderIdx++;
        }
        // 어디에서도 실을 수 없는 경우 메인 컨테이너에서 박스를 하나씩 보조 컨테이너로 옮김
        else if (!mainContainer.empty()) 
        {
            subContainer.push(mainContainer.front());
            mainContainer.pop();
        }
        // 메인 컨테이너도 비었고, 보조 컨테이너에서도 적재 불가능하면 종료
        else 
        {
            break;
        }
    }

    return answer;
}
