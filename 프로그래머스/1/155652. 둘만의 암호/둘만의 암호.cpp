#include <string>
#include <vector>
using namespace std;

string solution(string s,string skip,int index) {
    string answer ="";
    
    // 문자열 s의 각 알파벳을 index만큼 뒤의 알파벳으로 바꾼다.
    // 그 과정에 있는 알파벳이 skip에 있다면 세지 않는다.
    
    for(int i=0;i<s.size();i++){
        for(int j=0;j<index;j++){
            s[i]+=1;
            //skip에 있는지 검사
            if(s[i]>'z'){
                s[i] =s[i] -'z' -1+ 'a';
            }
            
            for(int k=0;k<skip.size();k++){
                if(s[i]==skip[k]){
                    j--;
                }
            }
        }
        answer+=s[i];
    }
    return answer;
}