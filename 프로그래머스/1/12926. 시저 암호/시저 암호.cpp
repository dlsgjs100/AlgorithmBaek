#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = s;
    int size=s.size();
    
    for(int i=0;i<size;i++){
        if(answer[i] != ' '){
            if (answer[i] >= 'a' && answer[i] <= 'z') { 
                answer[i] = 'a' + (answer[i] - 'a' + n) % 26;
                } 
            else if (answer[i] >= 'A' && answer[i] <= 'Z') { 
                answer[i] = 'A' + (answer[i] - 'A' + n) % 26;
                }
            }
        }
    
    return answer;
}