#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int index=0;
    
    for(int i=0;i<n;i++){
        if(index%2==0){
            answer+="수";
        }
        else{
            answer+="박";
        }
        index++;
    }
    
    return answer;
}