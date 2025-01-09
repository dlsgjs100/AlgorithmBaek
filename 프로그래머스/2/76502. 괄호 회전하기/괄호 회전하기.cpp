#include <string>
#include <vector>

using namespace std;

string rotate(const string& s){
    string rotated;
    for(int i=1;i<s.size();i++){
        rotated+=s[i];
    }
    rotated+=s[0];
    return rotated;
}

// 문자열이 올바른지 검사하는 함수
bool inspect(const string& s){
    vector<char> stack;
    // 여는 괄호가 나오면 스택에 저장하다가 닫는 괄호가 나오면 스택의 top과 비교하고 pop 
    for(int i=0;i<s.size();i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stack.push_back(s[i]);
        }
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            // 닫는괄호인데 스택이 비어있거나 마지막요소와 매칭되지않으면 false
            if (stack.empty() || 
                (s[i] == ')' && stack.back() != '(') || 
                (s[i] == '}' && stack.back() != '{') || 
                (s[i] == ']' && stack.back() != '[')) {
                return false;
            }
            stack.pop_back();
        }
    }
    return stack.empty();
}

int solution(string s) {
    int answer = 0;
    // 올바른 괄호 문자열
    // 열었으면 닫아야하고 순서를 지켜야 한다.
    for(int i=0;i<s.size();i++){
        s = rotate(s);
        if(inspect(s)){
            answer++;
        }
    }
    
    return answer;
}