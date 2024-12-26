#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int x=1;
    do{
        if(n % x == 1){
            answer = x;
            break;
        } 
        else{
            x++;
        }
    }while(x <= n);
    return answer;
}