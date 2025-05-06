#include <iostream>

using namespace std;

int roomNumber(const int& H, const int& W, const int& N)
{
    int room;
    // 6,12,10
    // 1 = 6*0 + 1 -> 101
    // 6 = 6*1 + 0 -> 601
    // 7 = 6*1 + 1 -> 102
    // 10 = 6 * 1 + 4 -> 402
    int quotient = N / H;
    int remainder = N % H;
	if (remainder == 0)
	{
		remainder = H;
		quotient--;
	}
    room = remainder * 100 + quotient + 1;
    return room;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int H, W, N; // 1 ~ 99 / 1 ~ 99 / 1 ~ 9801
        cin >> H >> W >> N;
        cout << roomNumber(H, W, N) << '\n';
    }
    return 0;
}