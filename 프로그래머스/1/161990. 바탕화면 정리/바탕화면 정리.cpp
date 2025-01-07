#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    // 한번의 드래그
    // lux luy
    // rdx rdy
    // wallpaper를 2차원으로 가장 끝파일들을 찾는다.
    // #이 처음 관측된 x,y좌표, #이 마지막으로 관측된 x+1,y좌표+1
    int minX=wallpaper.size();
    int minY=wallpaper[0].size();
    int maxX=-1;
    int maxY=-1;
    
    //[".#...", 
    // "..#..", 
    // "...#."]
    
    // 0 1
    // 1 2
    // 2 3
    // 0 1
    // 2 3
    
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].size();j++){
            if(wallpaper[i][j]=='#'){
                if(j<minY){
                    minY = j;
                }
                if(i<minX){
                    minX = i;
                }
                if(j>=maxY){
                    maxY = j+1;
                }
                if(i>=maxX){
                    maxX = i+1;
                }
            }
        }
    }
    answer.push_back(minX);
    answer.push_back(minY);
    answer.push_back(maxX);
    answer.push_back(maxY);
    return answer;
}