#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

string FindGood2(string& s) {
    string _a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_set<char> alphabet(_a.begin(), _a.end());
    int missing_cnt = 0;
    int left = 0, right = 25;
    if (s.size() < 26) {
        return "-1";
    }

    for (int i = left; i <= right; ++i) {
        if (s[i] == '?') {
            ++missing_cnt;
        }
    }

    while (right < s.size()) {
        unordered_set<char> unique;
        for (int i = left; i <= right; ++i) {
            if (s[i] != '?') {
                unique.insert(s[i]);
            }
        }

        if (unique.size() + missing_cnt == 26) {
            string result = s;
            unordered_set<char> used(unique.begin(), unique.end());
            auto it = alphabet.begin();
            for (int j = left; j <= right; ++j) {
                if (result[j] == '?') {
                    while (used.count(*it)) {
                        ++it;
                    }
                    result[j] = *it;
                    used.insert(*it);
                }
            }
            for (char& c : result) {
                if (c == '?') {
                    c = 'A';
                }
            }
            return result;
        }

        if (s[left] == '?') {
            --missing_cnt;
        }
        ++left;
        ++right;
        if (right < s.size() && s[right] == '?') {
            ++missing_cnt;
        }
    }

    return "-1";
}

int main() {
    string s;
    cin >> s;
    cout << FindGood2(s) << '\n';
    return 0;
}