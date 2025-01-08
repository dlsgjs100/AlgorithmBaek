#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    // s의 숫자들을 int형으로저장
    // 돌면서 최소값, 최대값 구하기
    // 문자열 형태로
    
    // s에는 둘 이상의 정수가 공백으로 구분되어있다.
    // 숫자의 개수부터 구한다.
    // 공백의 포지션을 찾고 substr로 자른다.
    int count=0;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            count++;
        }
    }
    count++; // 숫자의 개수는 공백의 개수 +1
    vector<string> strnum; // 자른 숫자들을 담을 벡터컨테이너
    
    int startPos=0; // 자르기 시작하는 위치
    for(int i=0;i<s.size();i++){
        //공백이 없는 경우(숫자가 하나 남은 경우) 처리
        if(i== s.size()-1){
            strnum.push_back(s.substr(startPos));
        }
        
        if(s[i]==' '){
            strnum.push_back(s.substr(startPos,i));
            startPos=i+1;
        }
    }
    
    vector<int> num(count);
    for(int i=0;i<count;i++){
        num[i] = stoi(strnum[i]);
    }
    
    int minimum = num[0];
    int maximum = num[0];

    for(int i=1;i<count;i++){
        minimum = min(minimum,num[i]);
        maximum = max(maximum,num[i]);
    }
    
    string strmin = to_string(minimum);
    string strmax = to_string(maximum);
    
    answer = strmin + " " + strmax;
    
    return answer;
}