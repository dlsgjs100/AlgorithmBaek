#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int size = seoul.size();
    int where = 0;
    
    for(int i=0;i<size;i++){
        if(seoul[i]=="Kim"){
            where = i;
            break;
            }
    }
    

    answer= answer + "김서방은 " + to_string(where) +"에 있다";
    
    return answer;
}