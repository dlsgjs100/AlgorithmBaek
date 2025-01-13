#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    // want : 정현이 원하는 제품
    // number : 원하는 제품의 수량
    // discount : 할인하는 제품
    // return 회원등록 날짜의 총 일수
    
    vector<string> wantCount;
    
    for(int i=0;i<number.size();i++){
        for(int j=0;j<number[i];j++){
            wantCount.push_back(want[i]);
        }
    }
    
    for(int i=0;i<discount.size()-9;i++){
        vector<string> discountTen;
        for(int j=0;j<10;j++){
            discountTen.push_back(discount[i+j]);
        }
        sort(wantCount.begin(),wantCount.end());
        sort(discountTen.begin(),discountTen.end());
        if(wantCount == discountTen){
            answer++;
        }
    }
    
    
    return answer;
}