#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int start = 0;

    do {
        int countX = 0;
        int countNotX = 0;
        char x = s[start];
        for (int i = start; i < s.size(); i++) 
        {
            if (s[i] == x) 
            {
                countX++;
            }
            else 
            {
                countNotX++;
            }
            if (countX == countNotX) 
            {
                start = i + 1;
                answer++;
                break;
            }
        }

        if (countX != countNotX) 
        {
            answer++;
            break;
        }

    } while (start < s.size());

    return answer;
}