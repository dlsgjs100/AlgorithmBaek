#include <iostream>

using namespace std;

int getRoomNumber(int H, int N)
{
    int floor = (N - 1) % H + 1;       // 층수: 1~H
    int room = (N - 1) / H + 1;        // 호수: 1~
    return floor * 100 + room;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int H, W, N;
        cin >> H >> W >> N;
        cout << getRoomNumber(H, N) << '\n'; // W는 입력만 받고 무시
    }

    return 0;
}
