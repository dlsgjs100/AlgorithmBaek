#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int count = sizes.size();
    
    for(int i=0;i<count;i++){
        if(sizes[i][0]<sizes[i][1]){
            swap(sizes[i][0],sizes[i][1]);
        }
    }
    
    int maxW=0;
    int maxH=0;
    
    for(int i=0;i<count;i++){
        if(sizes[i][0]>maxW){
            maxW = sizes[i][0];
        }
        if(sizes[i][1]>maxH){
            maxH = sizes[i][1];
        }
    }

    answer = maxW * maxH;
    
    return answer;
}