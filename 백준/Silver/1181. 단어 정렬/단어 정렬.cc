#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// 알파벳 소문자단어 N개 (1 ~ 20000)
// 길이가 짧은 것부터
// 같으면 사전순으로 정렬
// 중복은 하나만 남기고 제거 -> set 사용? 정렬에 부적합 -> vector로 복사
bool compare(const string& a,const string& b)
{
    if(a.size()!=b.size())
    {
        return a.size()<b.size();
    }
    return a<b;
}

int main()
{
    int N;
    cin>>N;
    set<string> wordsSet;
    vector<string> wordsVec;
    for(int i=0;i<N;i++)
    {
        string word;
        cin>>word;
        wordsSet.insert(word);
    }
    for(auto& word : wordsSet)
    {
        wordsVec.push_back(word);
    }
    sort(wordsVec.begin(), wordsVec.end(),compare);
    
    // 출력!
    for (const string& word : wordsVec)
    {
        cout << word << '\n';
    }
    
    return 0;
}