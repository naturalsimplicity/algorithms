#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <climits>

using namespace std;

void Solve()
{
    int l;
    cin >> l;
    int64_t x = 0;
    stack<int64_t> loops; 
    loops.push(1);
    for (int i = 0; i < l; ++i) {
        string type;
        cin >> type;
        if (type == "for") {
            int64_t n;
            cin >> n;
            if (loops.top() == -1 || n * loops.top() > UINT32_MAX) {
                loops.push(-1);
            } else {
                loops.push(n * loops.top());
            }
        } else if (type == "add") {
            int64_t curr_multiplier = loops.top();
            if (curr_multiplier == -1 || x + curr_multiplier > UINT32_MAX) {
                cout << "OVERFLOW!!!" << '\n';
                return;
            }
            x += curr_multiplier;
        } else if (type == "end") {
            loops.pop();
        }
    }
    cout << x << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve();
    return 0;
}