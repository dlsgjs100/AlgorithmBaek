#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    // R T
    // C F
    // J M
    // A N
    // n개의 질문, 7개의 선택지    
    // 매우 동의나 매우 비동의 선택지를 선택하면 3점을 얻습니다.
    // 동의나 비동의 선택지를 선택하면 2점을 얻습니다.
    // 약간 동의나 약간 비동의 선택지를 선택하면 1점을 얻습니다.
    // 모르겠음 선택지를 선택하면 점수를 얻지 않습니다.
    
    // 점수가 높은 것이 검사자의 성격유형
    // 같으면 사전순
    
    // 질문마다 판단하는 지표를 담은 1차원 문자열배열 survey {비동의, 동의}
    // 검사자가 각 질문마다 선택한 선택지를 담은 1차원 정수배열 choices {1매우비동의, 2비동의, 3약간비동의, 4모르, 5약간동의, 6동의, 7매우동의}
    
    // 성격유형별 점수를 저장하는 컨테이너
    // rt,cf,jm,an순으로 저장해 비교해서 성격유형확정
    vector<int> score(8,0);
    // survey가 ~면 어디에 저장
    // choices를 적당히 가공하는 것이 좋아보임
    // 4씩 빼서 음수면 비동의에 양수면 동의에 그 절대값을 해당하는 유형에 더한다.
    for(int i=0;i<choices.size();i++){
        choices[i] -= 4;
    }
    
    for(int i=0;i<choices.size();i++){
        if(choices[i]<0){
            if(survey[i][0]=='R'){
                score[0] += abs(choices[i]);
            }
            else if(survey[i][0]=='T'){
                score[1] += abs(choices[i]);
            }
            else if(survey[i][0]=='C'){
                score[2] += abs(choices[i]);
            }
            else if(survey[i][0]=='F'){
                score[3] += abs(choices[i]);
            }
            else if(survey[i][0]=='J'){
                score[4] += abs(choices[i]);
            }
            else if(survey[i][0]=='M'){
                score[5] += abs(choices[i]);
            }
            else if(survey[i][0]=='A'){
                score[6] += abs(choices[i]);
            }
            else if(survey[i][0]=='N'){
                score[7] += abs(choices[i]);
            }
        }
        else if(choices[i]>0){
            if(survey[i][1]=='R'){
                score[0] += choices[i];
            }
            else if(survey[i][1]=='T'){
                score[1] += choices[i];
            }
            else if(survey[i][1]=='C'){
                score[2] += choices[i];
            }
            else if(survey[i][1]=='F'){
                score[3] += choices[i];
            }
            else if(survey[i][1]=='J'){
                score[4] += choices[i];
            }
            else if(survey[i][1]=='M'){
                score[5] += choices[i];
            }
            else if(survey[i][1]=='A'){
                score[6] += choices[i];
            }
            else if(survey[i][1]=='N'){
                score[7] += choices[i];
            }
        }
    }

    score[0]>=score[1] ? answer+= "R" : answer+="T";
    score[2]>=score[3] ? answer+= "C" : answer+="F";
    score[4]>=score[5] ? answer+= "J" : answer+="M";
    score[6]>=score[7] ? answer+= "A" : answer+="N";
    
    return answer;
}