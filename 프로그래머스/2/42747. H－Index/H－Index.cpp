#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    // 어떤 과학자가 발표한 논문 n편 중, 
    // h번 이상 인용된 논문이 h편 이상이고 
    // 나머지 논문이 h번 이하 인용되었다면 
    // h의 최댓값이 이 과학자의 H-Index
    // citations : 어떤 과학자가 발표한 논문의 인용 횟수
    
    int n = citations.size();
    
    // 인용횟수 내림차순 정렬
    sort(citations.rbegin(), citations.rend());
    
    for(int i=0;i<n;i++){
        if(citations[i]>=i +1){
            answer = i+1;
        }
        else{
            break;   
        }
    }
    return answer;
}