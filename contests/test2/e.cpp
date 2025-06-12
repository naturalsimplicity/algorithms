#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int32_t, int>> v;
    for (int i = 0; i < n; ++i) {
        int32_t l, r;
        cin >> l >> r;
        v.emplace_back(l, 0);
        v.emplace_back(r, 1);
    }
    sort(v.begin(), v.end());

    int32_t max_segments = 0, curr_segments = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it->second == 0) {
            ++curr_segments;
        }
        if (curr_segments > max_segments) {
            max_segments = curr_segments;
        }
        if (it->second == 1) {
            --curr_segments;
        }
    }

    cout << max_segments << '\n';

    return 0;
}
