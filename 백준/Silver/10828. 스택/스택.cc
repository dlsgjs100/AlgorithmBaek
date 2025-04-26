#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr;
    
    while (N--)
    {
        string order;
        cin >> order;
        
        if (order == "push")
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        else if (order == "pop")
        {
            if (!arr.empty())
            {
                cout << arr.back() << "\n";
                arr.pop_back();
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else if (order == "size")
        {
            cout << arr.size() << "\n";
        }
        else if (order == "empty")
        {
            cout << (arr.empty() ? 1 : 0) << "\n";
        }
        else if (order == "top")
        {
            if (!arr.empty())
            {
                cout << arr.back() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }
    return 0;
}
