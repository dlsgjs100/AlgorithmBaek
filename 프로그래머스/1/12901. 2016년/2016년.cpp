#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> days = {31,29,31,30,31,30,31,31,30,31,30,31};
    // 1월 1일은 금요일
    // 1월이면 b
    // 2월이면 b + 31
    // 3월이면 b + 31 + 29
    int day=0;
    // 2월 이상이면
    // b에 days[0]부터 days[a-2]를 더한다 
    if(a==1){
        day = b-1;
    }
    else{
        for(int i=0;i<a-1;i++){
            day += days[i];
        }
        day += b-1;
    }
    
    vector<string> dayOfWeek = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    answer += dayOfWeek[day%7];
    
    return answer;
}