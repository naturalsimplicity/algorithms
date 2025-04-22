#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void Solve()
{
    int n;
    cin >> n;

    vector<int64_t> v;
    for (int i = 0; i < n; ++i) {
        int64_t e;
        cin >> e;
        v.push_back(e);
    }
    v.push_back(0);

    // stack of ascending order elements
    stack<pair<int64_t, int64_t>> s;
    int64_t max_height = 0; 
    for (int i = 0; i < n + 1; ++i) {
        int64_t top_idx = i;
        while (!s.empty() && s.top().second > v[i]) {
            top_idx = s.top().first;
            int64_t curr_height = (i - top_idx) * s.top().second;
            if (curr_height > max_height) {
                max_height = curr_height;
            }
            s.pop();
        }
        s.push(pair<int64_t, int64_t>(top_idx, v[i]));
    }

    cout << max_height << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve();
    return 0;
}