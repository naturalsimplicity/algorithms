#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template<typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) {
        in >> x;
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a) {
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

/*
event {
    type = {fish borns}
    time = time to birth
}
*/

// NOT A SOLUTION!

int TimeToBorn(int a)
{
    return max(1, 1000 - a);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    set<pair<int, int>> events;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        events.insert({TimeToBorn(a[i]), i});
    }

    int cur_time = 0, cur_pos = 0;
    while (true) {
        int t = events.begin() -> first;
        int i = events.begin() -> second;
        events.erase(events.begin());

        if (abs(i - cur_pos) > t - cur_time) {
            cout << "Finish" << '\n';
            return;
        }

        cur_pos = i;
        cur_time = t;
        ++a[i];
        events.insert({TimeToBorn(a[i]), i});

    }


}

int main()
{
    solve();
    return 0;
}