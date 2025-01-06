#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    // 아래서부터, 빵 – 야채 – 고기 - 빵
    // 완성된 햄버거를 포장
    // 1 - 2 - 3 - 1
    
    // 1231 부분열을 발견하면 햄버거 하나완성하고 쳐낸다.
    // 더 만들 수 없을 때 까지 반복
    // 이론상 가능한 최대 햄버거 수는 
    // ingredient.size() / 4
    /*
    vector<int> newIngredient;
    for(int j=0;j<ingredient.size()/4;j++){
        for(int i=0;i<ingredient.size();i++){
            if(ingredient[i]==1 && 
               ingredient[i+1]==2 && 
               ingredient[i+2]==3 && 
               ingredient[i+3]==1){
                answer++;
            }
            else{
                newIngredient.push_back(ingredient[i]);
            }
        }
        ingredient = newIngredient;
    }
    *///시간초과
    
    // newIngredient에 전부를 복제하지말고
    // 조리대에 재료를 추가해 완성되면 마지막 4개재료 제거
    vector<int> countertop;

    for (int i = 0; i < ingredient.size(); i++) {
        countertop.push_back(ingredient[i]);

        // 마지막 4개 요소가 1, 2, 3, 1인지 확인
        int size = countertop.size();
        if (size >= 4 && 
            countertop[size - 4] == 1 && 
            countertop[size - 3] == 2 && 
            countertop[size - 2] == 3 && 
            countertop[size - 1] == 1) {
            answer++; // 햄버거 하나 완성
            countertop.erase(countertop.end() - 4, 
                             countertop.end()); // 마지막 4개 요소 제거
        }
    }
    
    return answer;
}