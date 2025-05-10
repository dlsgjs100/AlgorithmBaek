#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        string answers;
        cin >> answers;
        int score = 0;
        int totalScore = 0;
        for (const char& ans : answers)
        {
            if (ans == 'O')
            {
                score++;
                totalScore += score;
            }
            else if (ans == 'X')
            {
                score = 0;
            }
        }
        cout << totalScore << '\n';
    }
    return 0;
}