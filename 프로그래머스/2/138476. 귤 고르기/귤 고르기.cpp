#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    // k : 한 상자에 담으려는 귤의 개수
    // tangerine : 귤의 크기를 담은 배열 [1, 3, 2, 5, 4, 5, 2, 3]
    // return 서로 다른 종류의 수의 최솟값
    
    // 귤의 크기별 개수를 조사
    // 개수가 많은 것부터 담아서 k개가 될 때까지
    // 남은 귤들의 종류의 수
    map<int,int> tanMap; // 크기, 개수
    
    for(int size : tangerine){
        tanMap[size]++;
    }
    
    vector<int> count; // 개수를 담은 배열
    for(auto it = tanMap.begin() ; it != tanMap.end();it++){
        count.push_back(it->second); // [1,2,2,1,2]
    }
    
    sort(count.begin(),count.end()); // [1,1,2,2,2]
    
    // k는 앞으로 담아야 할 개수
    while(k>0){ 
        k-=count[count.size()-1]; 
        count.pop_back();
        answer++; 
    }
    
    return answer;
}