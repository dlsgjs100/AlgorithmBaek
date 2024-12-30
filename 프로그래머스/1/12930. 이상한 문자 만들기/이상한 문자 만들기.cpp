#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int length = s.size();
    int index = 0;
    
    for(int i=0;i<length ; i++){
        if(s[i] == ' '){
            index = 0;
            answer+=" ";
        }
        else{
            if(index % 2== 0){
                if(s[i]>='a'){
                    answer += s[i] - 'a' + 'A';
                }
                else{
                    answer+= s[i];
                }
            }
            else{
                if(s[i]<'a'){
                    answer += s[i] - 'A' + 'a';
                }
                else{
                    answer+= s[i];
                }
            }
            index++;
        }
    }
    
    return answer;
}