#include <string>
#include <vector>

using namespace std;

// 선행 스킬 순서에 있는 스킬만 추출한다.
// 추출한 스킬트리는 선행스킬순서의 앞부분
// C, CB, CBD
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (auto skill_tree : skill_trees)
    {
        // 선행 스킬 순서에 있는 스킬만 추출
        string parsing = "";
        for (char oneSkill : skill_tree)
        {
            if (skill.find(oneSkill) != string::npos)
            {
                parsing += oneSkill;
            }
        }

        // parsing이 skill의 앞부분인지 확인
        bool isValid = true;
        for (int i = 0; i < parsing.size(); ++i)
        {
            if (parsing[i] != skill[i])
            {
                isValid = false;
                break;
            }
        }

        if (isValid)
        {
            answer++;
        }
    }

    return answer;
}