#include <string>
#include <vector>

using namespace std;

string Binaryconverse(int size){
    string result = "";
    int Quotient = size;
    vector<int> remainder;
    while(Quotient>0){
        remainder.push_back(Quotient % 2);
        Quotient = Quotient/2;
    }

    for(int i=remainder.size()-1;i>=0;i--){
        result += to_string(remainder[i]);
    }
    
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    // 1. s의 모든 0을 제거
    // 2. s를 s의 길이를 2진법으로 표현한 문자열로 바꿈
    // 3. s가 1이 될 때까지 반복했을 때 이진변환의 횟수와, 변환과정에서 제거된 모든 0의 개수
    
    int count=0;
    int countZero=0;
    
    string removedZero="";
    while(s != "1"){ // s가 1이될 때까지 반복
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){ // 1만 담아 새로운 문자열로
                removedZero.push_back(s[i]);
            }
            else{ // 제거된 0의 개수
                countZero++;
            }
        }

        int size =removedZero.size(); 
        // s는 s의 길이를 2진법으로 표현한 문자열
        s = Binaryconverse(size);

        removedZero="";
        count++;
    }
    
    answer.push_back(count);
    answer.push_back(countZero);
    
    return answer;
}