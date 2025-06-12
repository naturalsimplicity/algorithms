#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

string CheckAlmostCorrectBracketSequence(string& seq)
{
    stack<char> s;
    for (char c : seq) {
        if (s.size() > 0 && (
            c == '(' && s.top() == ')' || c == ')' && s.top() == '(' ||
            c == '[' && s.top() == ']' || c == ']' && s.top() == '[' ||
            c == '{' && s.top() == '}' || c == '}' && s.top() == '{'
            )
        ) {
            s.pop();
        } else {
            s.push(c);
        }
    }

    if (s.size() > 0) {
        return "No";
    } else {
        return "Yes";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string seq;
    cin >> seq;

    cout << CheckAlmostCorrectBracketSequence(seq) << '\n';
    
    return 0;
}
