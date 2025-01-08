#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    // s를 JadenCase로 리턴
    // s의 원소 : 숫자, 대문자, 소문자, 공백
    // 공백이 연속해서 나올 수 있음
    
    // 전체를 검사해서 
    // 1. 대문자면 소문자로
    // 2. 첫번째 원소가 소문자면 대문자로
    // 3. 공백다음이 소문자면 대문자로
    
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z'){ // 대문자면 소문자로
            s[i] = s[i]  -'A'+'a';
        }
    }
    
    if((s[0]>='a' && s[0]<='z')){
        s[0] = s[0]  -'a'+'A';
    }
    
    for(int i=0;i<s.size();i++){
        
        if(s[i]==' '&&(s[i+1]>='a' && s[i+1]<='z')){ // 공백다음이 소문자면 대문자로
            s[i+1] = s[i+1]  -'a'+'A';
        }
    }
     
    answer = s;
    
    return answer;
}