#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> genrePlayCount;
    unordered_map<string, vector<pair<int, int>>> genreSongs;

    // 1. 장르별 총 재생 수 & 노래 목록 저장
    for (int i = 0; i < genres.size(); ++i) 
    {
        genrePlayCount[genres[i]] += plays[i];
        genreSongs[genres[i]].emplace_back(-plays[i], i); // -plays[i]는 정렬 편의를 위해
    }

    // 2. 장르별 총 재생 수 기준 정렬
    vector<pair<string, int>> sortedGenres(genrePlayCount.begin(), genrePlayCount.end());
    sort(sortedGenres.begin(), sortedGenres.end(),
         [](const auto& a, const auto& b) 
         {
             return a.second > b.second;
         });

    // 3. 결과 생성
    vector<int> answer;
    for (size_t i = 0; i < sortedGenres.size(); ++i) 
    {
        string genre = sortedGenres[i].first;

        vector<pair<int, int>>& songs = genreSongs[genre];
        sort(songs.begin(), songs.end()); // -재생수, 고유번호 기준 정렬됨

        for (int j = 0; j < songs.size() && j < 2; ++j) 
        {
            answer.push_back(songs[j].second); // 고유 번호만 저장
        }
    }

    return answer;
}
