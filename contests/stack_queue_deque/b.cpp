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
    string u;
    stack<char> t;
    vector<int> count(26, 0);
    
    for (char c : s) {
        count[c - 'a']++;
    }
    
    int idx = 0;
    for (char c : s) {
        t.push(c);
        count[c - 'a']--;
        
        while (idx < 26 && count[idx] == 0) {
            idx++;
        }
        
        while (!t.empty() && (idx >= 26 || t.top() - 'a' <= idx)) {
            u.push_back(t.top());
            t.pop();
        }
    }
    
    while (!t.empty()) {
        u.push_back(t.top());
        t.pop();
    }
    
    cout << u << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve();
    return 0;
}