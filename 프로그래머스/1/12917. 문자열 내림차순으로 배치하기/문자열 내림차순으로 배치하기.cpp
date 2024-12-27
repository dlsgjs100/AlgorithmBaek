#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int size = s.size();
    
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(s[i]<=s[j]){
                swap(s[i],s[j]);
            }
        }
    }
    
    for(int i=0;i<size;i++){
        answer+=s[i];
    }
    
    return answer;
}