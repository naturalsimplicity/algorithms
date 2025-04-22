#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void GreaterInLeft()
{
    // find max j such that Aj > Ai and j < i
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        v.push_back(e);
    }

    // sequence of descending order elements
    stack<int> seq;
    for (int i = 0; i < n; ++i) {
        while (!seq.empty() && v[seq.top()] <= v[i]) {
            seq.pop();
        }
        if (seq.empty()) {
            cout << -1 << ' ';
        } else {
            cout << seq.top() + 1 << ' ';
        }
        seq.push(i);
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    GreaterInLeft();
    return 0;
}