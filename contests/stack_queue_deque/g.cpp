#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

bool is_matching(char left, char right)
{
    return left == '(' && right == ')' || left == '{' && right == '}' || left == '[' && right == ']';
}

void Solve()
{
    string s;
    cin >> s;
    stack<char> brackets;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            brackets.push(c);
        } else {
            if (!brackets.empty() && is_matching(brackets.top(), c)) {
                brackets.pop();
            } else {
                cout << "no" << '\n';
                return;
            }
        }
    }
    if (brackets.empty()) {
        cout << "yes" << '\n';
    } else {
        cout << "no" << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve();
    return 0;
}