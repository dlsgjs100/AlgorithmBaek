#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    // 빈 병 a개를 콜라 b개로 교환, n개를 주면 몇개를? 
    // 1 : 20/2 * b ... 10 * 1 + 0
    // 2 : 10/2 ... 5 * 1 + 0
    // 3 : 5/2 ... 2 * 1 + 1
    // 4 : 2/2 ... 1 * 1 + 1
    // 5 : 1<2 
    // 6 : 1 + 1 + 2 + 5 + 10
    
    // 1: n/a * b ... n/a * b + n-(n/a*b)
    
    // 1. n/a * b .. n/a * b + n%a
    // 2. ((n/a * b)/a)*b...0
    int count =0;
    
    while(n>=a){
        count += (n/a) * b;
        n = ((n/a) * b) + n%a; 
    }
    
    answer = count;
    
    
    return answer;
}