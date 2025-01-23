#include <string>
#include <vector>
#include <map>
#include <cmath> // ceil 함수 사용

using namespace std;

// "시:분" 형식의 시간을 분 단위로 변환
int convertToMinutes(const string& time) 
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) 
{
    map<int, int> totalTime; // 차량 번호별 누적 주차 시간
    map<int, int> lastInTime; // 차량 번호별 마지막 입차 시간
    vector<int> answer;

    for (const string& record : records) 
    {
        int time = convertToMinutes(record.substr(0, 5)); // 시각 변환
        int carNumber = stoi(record.substr(6, 4));        // 차량 번호 추출
        string status = record.substr(11);               // IN 또는 OUT

        if (status == "IN") 
        {
            lastInTime[carNumber] = time; // 입차 시각 저장
        } 
        else 
        { // OUT
            totalTime[carNumber] += time - lastInTime[carNumber]; // 주차 시간 누적
            lastInTime.erase(carNumber); // 출차 후 입차 기록 삭제
        }
    }

    // 출차 기록 없는 차량 처리 (23:59에 출차한 것으로 간주)
    for (const auto& record : lastInTime) 
    {
        int carNumber = record.first;
        int inTime = record.second;
        totalTime[carNumber] += convertToMinutes("23:59") - inTime;
    }

    // 요금 계산
    for (const auto& record : totalTime) 
    {
        int carNumber = record.first;
        int parkedTime = record.second;
        int fee = fees[1]; // 기본 요금

        if (parkedTime > fees[0]) 
        { // 기본 시간 초과 시 추가 요금 계산
            fee += ceil((double)(parkedTime - fees[0]) / fees[2]) * fees[3];
        }

        answer.push_back(fee);
    }

    return answer;
}
