#include <iostream>
#include <queue>

using namespace std;

// x가 자연수면 배열에 x추가
// x가 0이면 배열에서 가장 큰 값을 출력하고 배열에서 제거
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; // 1~100000
    cin >> N;
    priority_queue<int, vector<int>, less<>> pq;

    while (N--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }
    return 0;
}