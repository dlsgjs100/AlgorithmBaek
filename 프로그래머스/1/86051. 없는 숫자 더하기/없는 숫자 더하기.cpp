#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -1;
    int size = numbers.size();
    int sum=0;
    bool isExist=true;
    
    for(int i=0;i<=9;i++){
        for(int j=0;j<size;j++){
            if(numbers[j]==i){
                isExist=true;
                break;
                }
            }
        if(!isExist){
            sum+=i;
            }
        isExist=false;
        }
    
    answer = sum;
    
    return answer;
}