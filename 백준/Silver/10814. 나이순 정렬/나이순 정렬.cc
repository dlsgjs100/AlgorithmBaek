#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 나이순, 같으면 가입순
    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; // (1~100000)
    cin>>N;
    
    vector<pair<int, string>> members(N);
    for(int i = 0;i<N;i++)
    {
        cin>> members[i].first>>members[i].second;
    }
    
    stable_sort(members.begin(), members.end(), [](const auto& a, const auto& b)
                {
                    return a.first < b.first;
                });
    
    for(const auto& [age, name] : members)
    {
        cout<<age<<' '<<name<<'\n';
    }
    return 0;
}