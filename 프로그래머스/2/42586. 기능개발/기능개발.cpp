#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size();
    vector<int> days(size,0);
    
    for(int i=0;i<size;i++){
        days[i] = (100 - progresses[i] + speeds[i]-1)/speeds[i];
    }
    
    int i = 0; 
    while (i < size) {
        int count = 1; 
        int currentDay = days[i]; 
        
        while (i + 1 < size && days[i + 1] <= currentDay) {
            count++;
            i++;
        }
        
        answer.push_back(count);
        i++; 
    }
    
    return answer;
}