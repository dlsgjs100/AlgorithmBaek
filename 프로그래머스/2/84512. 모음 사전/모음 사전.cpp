#include <string>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

set<string> dictionary;
string currentWord = "";

void Dictionary(const string& alpha, string currentWord)
{
    if(currentWord.size()>5)
    {
        return ;
    }
    
    dictionary.insert(currentWord);
    
    for(char c : alpha)
    {
        Dictionary(alpha,currentWord+c);
    }
}

int solution(string word) {
    int answer = 0;
    // A ~ UUUUU
    // 사전의 몇 번째 단어인가
    
    Dictionary("AEIOU","");
    answer = distance(dictionary.begin(),dictionary.find(word));
    
    return answer;
}