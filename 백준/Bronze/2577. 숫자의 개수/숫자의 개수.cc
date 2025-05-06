#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    string num = to_string(A * B * C);
    vector<int> countVec(10);
    for (char alpha : num)
    {
        for (int i = 0; i < 10; i++)
        {
            if (alpha == i + '0')
            {
                countVec[i]++;
            }
        }
    }

    for (const int& count : countVec)
    {
        cout << count << '\n';
    }
    return 0;
}