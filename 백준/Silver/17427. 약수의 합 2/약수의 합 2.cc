#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int N;
    cin >> N;

    vector<int> f(N + 1, 0);

    for (int i = 1; i <= N; i++) 
    {
        for (int j = i; j <= N; j += i) 
        {
            f[j] += i;
        }
    }

    long long result = 0;
    for (int i = 1; i <= N; i++) 
    {
        result += f[i];
    }

    cout << result << '\n';
    return 0;
}