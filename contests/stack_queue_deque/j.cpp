#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <deque>

using namespace std;

void MinimumInWindow()
{
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        v.push_back(e);
    }

    // sequence of ascending order elements
    deque<int> seq;
    for (int i = 0; i < n; ++i) {
        if (!seq.empty() && seq.front() <= i - k) {
            seq.pop_front();
        }
        while (!seq.empty() && v[i] < v[seq.back()]) {
            seq.pop_back();
        }
        seq.push_back(i);
        if (i >= k - 1) {
            cout << v[seq.front()] << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    MinimumInWindow();
    return 0;
}