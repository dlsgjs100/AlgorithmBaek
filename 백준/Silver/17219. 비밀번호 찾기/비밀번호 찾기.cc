#include <iostream>
#include <unordered_map>

using namespace std;
// N 1~100000 / M 1~100000
// 주소 비번
// 찾는 주소
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,M;
    cin>>N>>M;
    
    unordered_map<string,string> memos;
    for(int i=0;i<N;i++)
    {
        string address;
        string password;
        cin>>address>>password;
        memos[address] = password;
    }

    for(int i=0;i<M;i++)
    {
        string address;
        cin>>address;
        cout<<memos[address]<<'\n';
    }
    return 0;
}