#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    // 모든 달은 28일까지
    // 약관의 유효기간이 지나면 파기
    // 오늘 날짜 today : "YYYY.MM.DD"
    // 약관의 유효기간 terms : "약관종류 유효기간"
    // 약관종류 : A~Z 중복안됨
    // 유효기간 : 개인정보를 보관할 수 있는 달 수를 나타내는 정수 1~100
    // 수집된 개인정보의 정보 privacies[i] : i+1 번 개인정보의 수집일자와 약관 종류
    // return 파기해야 할 개인정보의 번호를 오름차순으로 담은 1차원 정수 배열
    
    // today "2022.05.19"
    // terms ["A 6", "B 12", "C 3"]
    // privacies ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]
    // [1, 3]
    
    // today를 기준으로 수집일자로부터 유효기간이 지났으면 파기 
    // 약관종류를 보고 수집일자에 유효기간을 더한다.
    // 지났으면 answer에 담고 오름차순

    int todayYear = stoi(today.substr(0, 4));
    int todayMonth = stoi(today.substr(5, 7));
    int todayDay = stoi(today.substr(8, 10));
    
    unordered_map<char, int> termMap;
    
    for (const auto& term : terms) {
        char type = term[0];
        int duration = stoi(term.substr(2)); // 유효기간 (달 단위)
        termMap[type] = duration;
    }
    
     for (int i = 0; i < privacies.size(); i++) {
        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2));
        int day = stoi(privacies[i].substr(8, 2))-1;
        char type = privacies[i][11];

        int duration = termMap[type];
        month += duration;

        // 달 수가 12를 넘으면 연도로 변환
        year += (month - 1) / 12;
        month = (month - 1) % 12 + 1;

        // 날짜 비교
        if (year < todayYear || 
            (year == todayYear && month < todayMonth) ||
            (year == todayYear && month == todayMonth && day < todayDay)) {
            answer.push_back(i + 1);
        }
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}