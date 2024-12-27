#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    int size = arr.size();
    
    for(int i =0;i<size;i++){
        if(arr[i]%divisor==0){
            answer.push_back(arr[i]);
        }
    }
    
    int count = answer.size();
    
    if(count==0){
        answer.push_back(-1);
        return answer;
    }
    
    for(int i=0;i<count;i++){
        for(int j=i;j<count;j++){
            if(answer[i]>=answer[j]){
                swap(answer[i],answer[j]);
            }
        }
    }
    
    return answer;
}