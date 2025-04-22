#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void Solve()
{
    // Water in the castle
    int n;
    cin >> n;

    vector<int> h;
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        h.push_back(e);
    }

    int volume = 0;
    stack<int> desc;
    for (int i = 0; i < n; ++i) {
        if (desc.empty()) {
            desc.push(i);
            continue;
        }
        while (desc.size() > 1 && h[i] > h[desc.top()]) {
            int floor = desc.top();
            desc.pop();
            int width = i - desc.top() - 1;
            int height = min(h[desc.top()], h[i]) - h[floor];
            volume += width * height;
        }
        if (h[desc.top()] > h[i]) {
            desc.push(i);
        } else {
            desc.pop();
            desc.push(i);
        }
    }
    cout << volume << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve();
    return 0;
}