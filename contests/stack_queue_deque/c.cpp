#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void Solve()
{
    string seq;
    cin >> seq;
    stack<char> s;
    for (char c : seq) {
        if (!s.empty() && s.top() == c) {
            s.pop();
        } else {
            s.push(c);
        }
    }
    if (s.empty()) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve();
    return 0;
}