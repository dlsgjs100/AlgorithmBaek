#include <iostream>
#include <vector>

using namespace std;

// 다장조 : c d e f g a b C : 1 2 3 4 5 6 7 8
// ascending : 1 2 3 4 5 6 7 8
// descending : 8 7 6 5 4 3 2 1
// mixed
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> play;
    for (int i = 0; i < 8; i++)
    {
        int num;
        cin >> num;
        play.push_back(num);
    }
	vector<int> ascending = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> descending = { 8, 7, 6, 5, 4, 3, 2, 1 };

    if (play == ascending)
    {
        cout << "ascending" << '\n';
    }
    else if (play == descending)
    {
        cout << "descending" << '\n';
    }
    else
    {
        cout << "mixed" << '\n';
    }
    return 0;
}