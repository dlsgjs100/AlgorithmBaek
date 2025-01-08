#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    // 동일한 이용자의 동일한 유저에 대한 신고 중복X
    // 이용자의 ID가 담긴 문자열 배열 id_list
    // 각 이용자가 신고한 이용자의 ID 정보가 담긴 문자열 배열 report
        // "이용자id 신고한id"
    // 정지 기준이 되는 신고 횟수 k
    // return id_list에 담긴 id 순서대로 각 유저가 받은 결과 메일 수
    
    // 신고한id를 신고한 이용자id가 중복이 아니면 신고횟수++
    // 신고횟수>=k이면 신고한id를 신고한 이용자id에게 보내는 메일수++
    // 신고한id를 신고한 이용자id를 담을 컨테이너
    // 이용자id의 메일수를 담을 컨테이너
    
    // 1. report를 돌며 중복이 아니면 신고한 id에 해당하는 컨테이너에 이용자 id담기
    // <신고한id, <이용자id,중복여부>>
    map<string, map<string, bool>> reportMap;
    
    for(const string& reportCase : report){
        int space=0;
        for(int i=0;i<reportCase.size();i++){
            if(reportCase[i]==' '){
                space = i;
            }
        }
        // 공백기준으로 앞이 이용자id(reporter), 뒤가 신고한id(reported)
        string reporter = reportCase.substr(0, space); 
        string reported = reportCase.substr(space + 1); 
     
        // 신고받은 적 없으면 추가
        if(reportMap[reported][reporter] == false){
            reportMap[reported][reporter] = true;
        }
    }
    
    // 2. k이상인 이용자 정지
    for(const auto& reportCase : reportMap){
        const string& reported = reportCase.first;
        const auto& reporters = reportCase.second;
        
        //신고한 이용자의 수가 k이상이면
        if(reporters.size()>=k){
            for(int i=0;i<id_list.size();i++){
                for(const auto& reporter : reporters){
                    if(reporter.first==id_list[i]){
                        answer[i]++;
                    }
                }
            }
        }
    }
    
    
    return answer;
}