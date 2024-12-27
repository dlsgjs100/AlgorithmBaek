#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int size = phone_number.size();
    const int showingNum = 4;
    
    for(int i=0;i<size-showingNum;i++){
        answer+="*";
    }
    for(int i=size-showingNum;i<size;i++){
        answer+=phone_number[i];
    }
    
    return answer;
}