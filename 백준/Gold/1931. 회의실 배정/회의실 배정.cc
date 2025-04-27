#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> meetings; // (끝나는 시간, 시작 시간)

    while(N--)
    {
        int start,end;
        cin>>start>>end;
        // 빨리 끝나는 회의잡으면 남은시간 더 많음
        meetings.push_back(make_pair(end,start));
    }
    
    sort(meetings.begin(),meetings.end());
    
    int count = 0;
    int lastEndTime = 0;
    for(auto& meeting : meetings)
    {
        if(meeting.second >= lastEndTime)
        {
            lastEndTime = meeting.first;
            count++;
        }
    }
    
    cout<<count<<"\n";
    return 0;
}
