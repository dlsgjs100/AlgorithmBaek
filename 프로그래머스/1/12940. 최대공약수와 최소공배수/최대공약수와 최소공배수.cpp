#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int gcd=0;
    int lcm=0;
    
    if(n<m){
        int temp=n;
        n=m;
        m=temp;
    }
    
    for(int i=1;i<=m;i++){
        if(n%i==0 && m%i==0){
            gcd=i;
        }
    }
    
    lcm = n / gcd * m;
    
    answer.push_back(gcd);
    answer.push_back(lcm);
    
    return answer;
}