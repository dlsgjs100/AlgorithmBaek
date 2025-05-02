#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b)
{
    if (a.size() != b.size()) 
    {
        return a.size() < b.size();
    }
    return a < b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_set<string> uniqueSet;
    vector<string> words;

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;

        // 중복 안 넣기
        if (uniqueSet.insert(word).second)
        {
            words.push_back(word);
        }
    }

    sort(words.begin(), words.end(), compare);

    for (const auto& word : words)
    {
        cout << word << '\n';
    }

    return 0;
}
