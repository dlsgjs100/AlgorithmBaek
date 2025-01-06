#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    // 알파벳을 최소 숫자로 치환해서 targets의 각 문자열을 작성하기 위한 최소 키입력을 구한다.
    // keymap의 각 문자에 대한 최소 키 횟수를 저장
    vector<vector<int>> alphabet(26,vector<int>(keymap.size(),101));
    
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].size(); j++) {
            char c = keymap[i][j];
            alphabet[c - 'A'][i] = min(alphabet[c - 'A'][i], j + 1);
        }
    }
                            
    for (string& target : targets) {
        int totalPress = 0;

        for (char c : target) {
            int minPress = 101;
            // 각 문자가 keymap에 있는지 확인하고 최소 눌러야 하는 횟수 찾기
            for (int i = 0; i < keymap.size(); i++) {
                minPress = min(minPress, alphabet[c - 'A'][i]);
            }

            if (minPress == 101) {  // 해당 문자가 keymap에 없다면
                totalPress = -1;
                break;
            }
            totalPress += minPress;
        }

        answer.push_back(totalPress);
    }
     
    
    return answer;
}