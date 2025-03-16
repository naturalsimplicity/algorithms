#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

void Solve(set<pair<int, int>>& s, int m)
{
    set<pair<int, int>> selected;
    auto it = s.begin();
    int left = 0, right = 0; // 0 2
    int next_left = 0, next_right = 0; // 1 5
    while (it != s.end()) {
        // cout << "left=" << left << ",right=" << right << '\n';
        if (it->second < 0) {
            ++it;
            continue;
        }
        if (it->first > m) {
            break;
        }
        if (it->first <= right) {
            if (it->second >= next_right) {
                next_left = it->first, next_right = it->second;
            }
        } else {
            if (selected.size() == 0) {
                if (next_left == -1 && next_right == -1) {
                    break;
                }
            }
            selected.insert(pair<int, int>(next_left, next_right));
            left = next_left, right = next_right;
            next_left = it->first, next_right = it->second;
            if (next_left > right) {
                break;
            }
        }
        if (next_right >= m) {
            selected.insert(pair<int, int>(next_left, next_right));
            cout << selected.size() << '\n';
            for (auto its = selected.begin(); its != selected.end(); ++its) {
                cout << its->first << ' ' << its->second << '\n';
            }
            return;
        }
        ++it;
    }
    cout << "No solution" << '\n';
}

int main()
{
    int m;
    cin >> m;
    set<pair<int, int>> s;
    int l, r;
    cin >> l >> r;
    while (l != 0 || r != 0) {
        s.insert(pair<int, int>(l, r));
        cin >> l >> r;
    }
    Solve(s, m);
    return 0;
}