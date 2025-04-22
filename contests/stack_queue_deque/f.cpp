#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void Solve()
{
    queue<int> q1, q2;
    for (int i = 0; i < 5; ++i) {
        int a;
        cin >> a;
        q1.push(a);
    }
    for (int i = 0; i < 5; ++i) {
        int b;
        cin >> b;
        q2.push(b);
    }

    for (int i = 0; i < 1000000; ++i) {
        if (q1.front() > q2.front() && (q1.front() != 9 || q2.front() != 0) || q1.front() == 0 && q2.front() == 9) {
            q1.push(q1.front());
            q1.push(q2.front());
        } else {
            q2.push(q1.front());
            q2.push(q2.front());
        }
        q1.pop();
        q2.pop();

        if (q1.empty()) {
            cout << "second " << i + 1 << '\n';
            return;
        } else if (q2.empty()) {
            cout << "first " << i + 1 << '\n';
            return;
        }
    }
    cout << "botva" << '\n';

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve();
    return 0;
}