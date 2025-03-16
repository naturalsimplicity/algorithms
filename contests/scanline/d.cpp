#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

void Solve()
{
    int n;
    cin >> n;
    int opened = 0;
    // event { time: time in seconds, type: 0 - open, 1 - close }
    vector<pair<int, int>> events;
    for (int i = 0; i < n; ++i) {
        int hh, mm, ss;
        cin >> hh >> mm >> ss;
        int start_time = hh * 60 * 60 + mm * 60 + ss; // first second when a cash desk is opened
        cin >> hh >> mm >> ss;
        int end_time = hh * 60 * 60 + mm * 60 + ss; // first second when a cash desk is closed
        events.push_back(pair<int, int>(start_time, 0));
        events.push_back(pair<int, int>(end_time, 1));
        if (start_time >= end_time) {
            // for cases when cash desk either opened round the clock or opened on one day and closed on the next day
            ++opened;
        }
    }
    sort(events.begin(), events.end());
    bool is_all_opened = (opened == n ? true : false);
    int all_opened_duration = 0;
    int start_time;
    int cur_event = 0;
    while (cur_event < 2*n) {
        if (events[cur_event].second == 0) {
            ++opened;
        } else {
            --opened;
        }
        if (opened == n) {
            is_all_opened = true;
            start_time = events[cur_event].first;
        } else if (is_all_opened) {
            is_all_opened = false;
            int end_time = events[cur_event].first;
            all_opened_duration += end_time - start_time;
        }
        // cout << "cur_event=" << cur_event << ",cur_time=" << events[cur_event].first << ",cur_type=" << events[cur_event].second << ",opened=" << opened << '\n';
        ++cur_event;
    }
    if (is_all_opened) {
        int end_time = 24 * 60 * 60;
        all_opened_duration += end_time - start_time;
    }
    cout << all_opened_duration << '\n';
}

int main()
{
    Solve();
    return 0;
}