#include <string>
#include <vector>
//#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    /*
    // X,Y의 공통된 숫자들을 골라낸다음
    // 그 숫자들로 만들 수 있는 가장 큰 수 
    vector<long long> temp;
    
    for(int i=0;i<X.size();i++){
        for(int j=0;j<Y.size();){
            if(X[i]==Y[j]){
                temp.push_back(X[i] - '0');
                Y.erase(Y.begin()+j);
                break;
            }
            else{
                j++;
            }
        }
    }
    
    sort(temp.begin(),temp.end());
    
    if(temp.empty()){
        answer += "-1";
    }
    else{
        for(int i=temp.size()-1;i>=0;i--){
            answer+=to_string(temp[i]);
        }
        if(answer[0]=='0'){
            answer="0";
        }
    }*/ 
    // 이중for문 + string메서드 시간초과
    
    // X,Y가 각각 어떤 숫자를 몇개 갖고있는지 먼저 추려서
    // 더 적은 개수만큼 그 숫자를 사용해서 숫자 만들기
    vector<int> countX(10,0);
    vector<int> countY(10,0);
    for(char c : X) countX[c-'0']++;
    for(char c : Y) countY[c-'0']++;
    
    for (int i = 9; i >= 0; i--) {
        int common = min(countX[i], countY[i]);
        answer += string(common, '0' + i);
    }
    
    if (answer.empty()) return "-1";     
    if (answer[0] == '0') return "0";    
    
    return answer;
}