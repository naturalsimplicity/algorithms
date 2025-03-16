#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

void GetMinSectionCount(set<pair<int, int>>& s, int n)
{
    /*
    event {
        type = {open/close}
        time = coordinate    
    }
    */
    set<pair<int, int>> joint;
    int min_section_count = 0;
    int count = 0;
    int left = -1, right = -1;
    auto it = s.begin();
    while (it != s.end()) {
        if (count == 0) {
            left = it->first;
            right = it->second;
            ++count;
            ++min_section_count;
            ++it;
        } else {
            if (it->first <= right) {
                right = max(right, it->second);
                ++it;
            } else {
                joint.insert(pair<int, int>(left, right));
                count = 0;
            }
        }
    }
    joint.insert(pair<int, int>(left, right));

    cout << min_section_count << '\n';
    for (auto it = joint.begin(); it != joint.end(); ++it) {
        cout << it->first << ' ' << it->second << '\n';
    }
}


int main()
{
    int n;
    cin >> n;
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        s.insert(pair<int, int>(l, r));
    }
    GetMinSectionCount(s, n);
    return 0;
}
