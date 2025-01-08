#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // brown : 갈색 격자의 수. 8 이상 5,000 이하인 자연수
    // yellow : 노란색 격자의 수. 1 이상 2,000,000 이하인 자연수
    // return [row, col]. row>=col
    
    // yellow = (row-2) * (col-2)
    // brown = row * col - yellow
    // row + col = (brown + 4) / 2
    // row * col = yellow + brown => y+b의 약수중 하나
    
    // row와 col은 yellow + brown의 약수
    vector<int> row;
    vector<int> col;
    
    // row에 약수를 저장
    for(int i=1;i<=yellow + brown;i++){
        row.push_back((yellow + brown)/i);
    }
    
    // 다른 관계식으로부터 col후보 저장
    for(int i=0;i<row.size();i++){
        col.push_back(((brown + 4) / 2)-row[i]);
    }
    
    for(int i=0;i<row.size();i++){
        if(row[i] * col[i] == yellow + brown && row[i]>=col[i] && col[i]>0){
            answer.push_back(row[i]);
            answer.push_back(col[i]);
        }
    }
    
    return answer;
}