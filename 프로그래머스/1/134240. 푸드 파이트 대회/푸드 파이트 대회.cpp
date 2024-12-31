#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    // 1 3 4 6
    // 0 -> 1
    // 1 -> 3
    // 2 -> 4
    // 3 -> 6
    // 1 22 333 0 333 22 1
    // 3/2 4/2 6/2 
    
    int count = food.size();
    string oneside = "";
    
    for(int i=1;i<count;i++){
        for(int j=0;j<food[i]/2;j++){
            oneside += to_string(i);
        }
    }
    
    int length = oneside.size();
    
    answer = oneside + "0";
    for(int i=0;i<length;i++){
        answer +=oneside[length-i-1];
    }
    
    
    return answer;
}