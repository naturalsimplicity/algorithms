#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

struct event {
    int64_t x, type, y1, y2;
    event (int64_t x, int64_t type, int64_t y1, int64_t y2):
        x(x), type(type), y1(y1), y2(y2) {}

    bool operator< (const event& e) const {
        if (x != e.x) return x < e.x;
        if (type != e.type) return type < e.type;
        if (y1 != e.y1) return y1 < e.y1;
        return y2 < e.y2;
    }
};

void Solve()
{
    int n;
    cin >> n;
    vector<event> events;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back(event(x1, 0, y1, y2));
        events.push_back(event(x2, 1, y1, y2));
    }
    sort(events.begin(), events.end());

    multiset<pair<int, int>> blocks;
    int64_t square = 0;
    int prev_x = -1;
    for (auto it = events.begin(); it != events.end(); ++it) {
        // cout << "x=" << it->x << ", type=" << it->type << ", y1=" << it->y1 << '\n';
        if (it != events.begin() && it->x > prev_x) {
            int max_y = -1;
            for (auto b = blocks.begin(); b != blocks.end(); ++b) {
                square += max(b->second - max(b->first, max_y), 0) * (it->x - prev_x);
                max_y = max(b->second, max_y);
            }
        }
        // cout << "blocks.size=" << blocks.size() << ", square=" << square << '\n';

        pair<int, int> block(it->y1, it->y2);
        if (it->type == 0) {
            blocks.insert(block);
        } else {
            auto pos = blocks.find(block);
            blocks.erase(pos);
        }
        prev_x = it->x;
    }

    cout << square << '\n';
}

int main()
{
    Solve();
    return 0;
}