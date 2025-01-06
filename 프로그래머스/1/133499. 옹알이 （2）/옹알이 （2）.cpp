#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    // "aya", "ye", "woo", "ma"
    // 연속하지 못함
    // babbling중 몇개나 따라할 수 있나
    for(int i=0;i<babbling.size();i++){
        
        int type=0;
        bool isValid = true;
        
        for(int j=0;j<babbling[i].size();){
            if(type!=1 && babbling[i].substr(j,3)=="aya"){
                type=1;
                j+=3;
            }
            else if(type!=2 && babbling[i].substr(j,2)=="ye"){
                type=2;
                j+=2;
            }
            else if(type!=3 && babbling[i].substr(j,3)=="woo"){
                type=3;
                j+=3;
            }
            else if(type!=4 && babbling[i].substr(j,2)=="ma"){
                type=4;
                j+=2;
            }
            else{
                isValid = false;
                break;
            }
        }
        
        if(isValid){
            answer++;
            }
        }
    
    return answer;
}