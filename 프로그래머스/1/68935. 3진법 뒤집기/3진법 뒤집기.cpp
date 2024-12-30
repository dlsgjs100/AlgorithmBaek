#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> vec;
    int count = 0;
    
    do{
        count++;
        vec.push_back(n%3);
        n/=3;
    }while(n!=0);
    
    for(int i=0;i<count;i++){
        int temp=1;
        for(int j=1;j<=i;j++){
            temp*=3;
        }
        answer += vec.back() * temp;
        vec.pop_back();
    }
    
    return answer;
}