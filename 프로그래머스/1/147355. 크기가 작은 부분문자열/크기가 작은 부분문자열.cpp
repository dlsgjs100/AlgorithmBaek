#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int digit = p.size();
    long long numP=0;

    for(int i=0;i<digit;i++){
        numP = numP*10 + (p[i]-'0');
    }
    
    int sizeT = t.size();
    
    for(int i=0;i<=sizeT - digit;i++){
        long long numT=0;
        for (int j = 0; j < digit; j++) {
            numT = numT * 10 + (t[i + j] - '0');
            }
        
        if(numT<=numP){
            answer++;
        }
    }
    return answer;
}