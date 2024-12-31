#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int size = s.size();
    
    // banana 6
    // 5 - 4 3 2 1 0
    // 4 - 3 2 1 0
    // 3 - 2 1 0
    // 2 - 1 0
    // 1 - 0
    // 0
    
    for(int i=0;i<size;i++){
        for(int j=i-1;j>=0;j--){
            if(s[i]==s[j]){
                answer.push_back(i-j);
                break;
            }
        }
        if(answer.size()<=i){
            answer.push_back(-1);
        }
    }
    
    return answer;
}