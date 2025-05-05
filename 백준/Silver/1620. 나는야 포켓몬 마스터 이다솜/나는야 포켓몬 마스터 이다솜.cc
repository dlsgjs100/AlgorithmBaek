#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
// 포켓몬 번호가 1번인 포켓몬부터 N번에 해당하는 포켓몬까지 한 줄에 하나씩 입력
// 이름의 첫글자만 대문자 나머지는 소문자, 영어로만 이루어짐
// 일부 포켓몬은 마지막만 대문자, 길이는 2~20
// M개의 줄에 맞춰야 하는 문제가 입력
// 알파벳으로 들어오면 번호 / 숫자로 들어오면 문자
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> nameToNum;
    unordered_map<int, string> numToName;

    for (int i = 1; i <= N; ++i)
    {
        string name;
        cin >> name;
        nameToNum[name] = i;
        numToName[i] = name;
    }

    for (int i = 0; i < M; ++i)
    {
        string query;
        cin >> query;
        if (isdigit(query[0]))  // 숫자로 시작하면 번호로 간주
        {
            int num = stoi(query);
            cout << numToName[num] << '\n';
        }
        else  // 문자열이면 이름으로 간주
        {
            cout << nameToNum[query] << '\n';
        }
    }

    return 0;
}