#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long x = 0;
    do{
        x++;
    }while(x * x < n);
    answer = (x * x == n) ? (x + 1) * (x + 1) : -1;
    
    return answer;
}