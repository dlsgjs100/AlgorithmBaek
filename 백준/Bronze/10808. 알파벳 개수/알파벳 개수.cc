#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> countAlpha(26, 0);
    for (char alpha : s)
    {
        countAlpha[alpha - 'a']++;
    }
    for (int count : countAlpha)
    {
        cout << count << " ";
    }
    return 0;
}