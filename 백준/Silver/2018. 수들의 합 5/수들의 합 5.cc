#include <iostream>

using namespace std;

int countSerialSum(const int& N)
{
    // 1부터 출발하여
    // 연속된 자연수를 더하다가 N과 같아지면 방법++, 커지면 다음 숫자로, N까지
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = i; j <= N; j++)
        {
            sum += j;
            if (sum > N)
            {
                break;
            }
            else if (sum == N)
            {
                count++;
                break;
            }
        }
    }
	return count;
}

int main()
{
    int N;
    cin >> N;
    cout << countSerialSum(N);
    return 0;
}