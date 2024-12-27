#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int sum=0;
    
    for(int i=left;i<=right;i++){
        sum+=i;
        for(int j=0;j<32;j++){
            if(i==j*j){
                sum-=i;
                sum-=i;
            }
        }
    }
    
    answer = sum;
    
    return answer;
}