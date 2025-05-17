#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),[](const vector<int>& a, const vector<int>& b)
         {
             return a[1] < b[1];
         });

    int camera = -300001;
    for(const auto route : routes)
    {
        int entry = route[0];
        int exit = route[1];
        
        if(entry > camera)
        {
            camera = exit;
            answer++;
        }
    }
    return answer;
}