#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int size = arr.size();
    int min=arr[0];
    
    for(int i=0;i<size;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    
    for(int i = 0;i<size;i++){
        if(arr[i]!=min){
            answer.push_back(arr[i]);
        }
    }
    
    if(answer.size()==0){
        answer.push_back(-1);
    }
    
    return answer;
}