#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

void CountPointsInSections(vector<pair<int, int>>& sections, vector<int>& points)
{
    sort(sections.begin(), sections.end());
    vector<int> points_in_sections(points.size());
    vector<int> points_idx(points.size());
    iota(points_idx.begin(), points_idx.end(), 0);
    sort(points_idx.begin(), points_idx.end(),
        [&points](int i1, int i2) {return points[i1] < points[i2];});

    int opened = 0;
    int cur_time = min(points.front(), sections.front().first);
    int cur_section = 0;
    int cur_point = 0;
    while (cur_time <= points[points_idx.back()]) {
        // cout << "cur_time=" << cur_time << '\n';
        int to_close = 0;
        while (true) {
            if (cur_section < sections.size() && cur_time == sections[cur_section].first) {
                if (sections[cur_section].second == 0) {
                    ++opened;
                } else {
                    ++to_close;
                }
                ++cur_section;
            } else {
                break;
            }
        }
        // cout << "cur_section=" << cur_section << "opened=" << opened << '\n';
        while (true) {
            if (cur_point < points.size() && cur_time == points[points_idx[cur_point]]) {
                points_in_sections[points_idx[cur_point]] = opened;
                ++cur_point;
            } else {
                break;
            }
        }
        opened -= to_close;
        // cout << "cur_section=" << cur_section << "opened=" << opened << '\n';
        ++cur_time;
    }
    for (int i = 0; i < points.size(); ++i) {
        cout << points_in_sections[i] << ' ';
    }
    cout << '\n';
}

void CountPointsInSections2(vector<pair<int, int>>& events, vector<int>& points)
{
    sort(events.begin(), events.end());
    vector<int> points_in_sections(points.size());
    vector<int> points_idx(points.size());
    iota(points_idx.begin(), points_idx.end(), 0);
    sort(points_idx.begin(), points_idx.end(),
        [&points](int i1, int i2) {return points[i1] < points[i2];});

    int opened = 0;
    int cur_point = 0;
    int cur_event = 0;
    while (cur_event < events.size()) {
        if (events[cur_event].second == 0) { // open
            ++opened;
        } else if (events[cur_event].second == 1) { // point
            points_in_sections[points_idx[cur_point]] = opened;
            ++cur_point;
        } else { // close
            --opened;
        }
        // cout << "cur_event=" << cur_event << ",cur_value=" << events[cur_event].first << ",cur_point=" << cur_point << ",opened=" << opened << '\n';
        ++cur_event;
    }
    for (int i = 0; i < points.size(); ++i) {
        cout << points_in_sections[i] << ' ';
    }
    cout << '\n';
}


int main()
{
    int n, m;
    cin >> n >> m;
    // event {time: coordinate, type: 0 (open), 1 (point), 2 (close)}
    vector<pair<int, int>> events(2*n+m); 
    vector<int> points(m);
    int i = 0;
    while (i < 2 * n) {
        int a, b;
        cin >> a >> b;
        events[i].first = min(a, b);
        events[i].second = 0;
        ++i;
        events[i].first = max(a, b);
        events[i].second = 2;
        ++i;
    }
    for (int j = 0; j < m; ++j) {
        int p;
        cin >> p;
        points[j] = p;
        events[i].first = p;
        events[i].second = 1;
        ++i;
    }
    CountPointsInSections2(events, points);

    return 0;
}