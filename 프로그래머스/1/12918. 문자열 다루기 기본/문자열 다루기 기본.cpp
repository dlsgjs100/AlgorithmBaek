#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    // '0' = 48 , '9' = 57
    int size = s.size();
    
    if(size == 4 || size == 6){
        for(int i=0;i<size;i++){
            if(s[i]<'0'||s[i]>'9'){
                answer = false;
                return answer;
                }
            }
        }
    else{
        answer = false;
    }
    
    
    
    return answer;
}