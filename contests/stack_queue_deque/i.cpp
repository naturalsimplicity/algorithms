#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <deque>

using namespace std;

void PrintDeque(deque<int>& d) 
{
    for (auto it = d.begin(); it != d.end(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';
}

void Solve()
{
    int n;
    cin >> n;

    deque<int> q1, q2; // first and second half of common queue
    // support q1 and q2 in a way that each new privileged element in the common queue
    // is pushed after the last element of q1
    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        int g;
        if (command == "+") {
            cin >> g;
            q2.push_back(g);
            if (q1.size() != q2.size()) {
                q1.push_back(q2.front());
                q2.pop_front();
            }
        } else if (command == "*") {
            cin >> g;
            if (q1.size() != q2.size()) {
                q2.push_front(g);
            } else {
                q1.push_back(g);
            }
        } else {
            cout << q1.front() << '\n';
            q1.pop_front();
            if (q1.size() != q2.size()) {
                q1.push_back(q2.front());
                q2.pop_front();
            }
        }
        // PrintDeque(q1);
        // PrintDeque(q2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve();
    return 0;
}