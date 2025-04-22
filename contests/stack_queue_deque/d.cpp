#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void Solve()
{
    string s;
    cin >> s;
    stack<int> open;
    int max_length = 0, count = 1, start = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            open.push(i);
        } else {
            if (open.empty()) {
                start = i;
                continue;
            }
            open.pop();
            int length;
            if (open.empty()) {
                length = i - start;
            } else {
                length = i - open.top();
            }

            if (length > max_length) {
                max_length = length;
                count = 1;
            } else if (length == max_length) {
                ++count;
            }   
        }
    }
    cout << max_length << ' ' << count << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve();
    return 0;
}