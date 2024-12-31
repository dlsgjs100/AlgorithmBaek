#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int count = numbers.size();
    
    for(int i=0;i<count-1;i++){
        for(int j=i+1;j<count;j++){
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    
    sort(answer.begin(),answer.end());
    
    int size = answer.size();
    for(int i = 0;i<size-1;i++){
        if(answer[i]==answer[i+1]){
            answer.erase(answer.begin()+i);
            size--;
            i--;
        }
    }
    
    return answer;
}