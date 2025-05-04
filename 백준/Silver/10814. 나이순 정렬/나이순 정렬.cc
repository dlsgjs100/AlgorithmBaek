#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, string>> members(N);
    for (auto& [age, name] : members) {
        cin >> age >> name;
    }

    stable_sort(members.begin(), members.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    for (const auto& [age, name] : members) {
        cout << age << ' ' << name << '\n';
    }

    return 0;
}
