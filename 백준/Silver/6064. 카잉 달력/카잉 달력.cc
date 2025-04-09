#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        int answer = -1;
        int maxYear = M * N;

        for (int k = x; k <= maxYear; k += M)
        {
            if ((k - 1) % N + 1 == y) 
            {
                answer = k;
                break;
            }
        }

        cout << answer << endl;
    }
    return 0;
}