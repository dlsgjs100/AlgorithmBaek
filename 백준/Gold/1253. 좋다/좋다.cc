#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    
    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        int target = vec[i];
        int start = 0, end = N - 1;

        while (start < end)
        {
            if (start == i) 
            {
                start++; 
                continue; 
            }
            if (end == i)
            { 
                end--; 
                continue; 
            }

            int sum = vec[start] + vec[end];
            if (sum == target)
            {
                count++;
                break;
            }
            else if (sum < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    cout << count << '\n';
    return 0;
}