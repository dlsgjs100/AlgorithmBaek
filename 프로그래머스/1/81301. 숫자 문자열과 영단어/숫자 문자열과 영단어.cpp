#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int size = s.size();
    string number;
    
    for(int i=0;i<size;i++){
        if(s[i]>='0' && s[i]<='9'){
            number.push_back(s[i]);
        }
        else if(s[i] == 'z'){
            number.push_back('0');
            i+=3;
        }
        else if(s[i] == 'o'){
            number.push_back('1');
            i+=2;
        }
        else if(s[i] == 't'){
            if(s[i+1] == 'w'){
                number.push_back('2');
                i+=2;
                }
            else{
                number.push_back('3');
                i+=4;
                }
        }
        else if(s[i] == 'f'){
            if(s[i+1] == 'o'){
                number.push_back('4');
                i+=3;
                }
            else{
                number.push_back('5');
                i+=3;
                }
            }
        else if(s[i] == 's'){
            if(s[i+1] == 'i'){
                number.push_back('6');
                i+=2;
                }
            else{
                number.push_back('7');
                i+=4;
                }
            }
        else if(s[i] == 'e'){
            number.push_back('8');
            i+=4;
        }
        else if(s[i] == 'n'){
            number.push_back('9');
            i+=3;
        }
    }
    
    for(int i=0;i<number.size();i++){
        answer = answer * 10 + (number[i]-'0');
    }
    
    return answer;
}