#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define int long long

using namespace std;

int log(int n)
{
    int res = 1, power = 0;
    while (n > res) {
        ++power;
        res *= 2;
    }
    return power;
}

int left(int v)
{
    return 2 * v + 1;
}

int right(int v)
{
    return 2 * v + 2;
}

void update(vector<int>& t, int v, int l, int r, int pos, int x)
{
    if (r - l == 1) {
        t[v] = x;
    } else {
        int m = (r + l) / 2;
        if (pos < m) {
            update(t, left(v), l, m, pos, x);
        } else {
            update(t, right(v), m, r, pos, x);
        }
        t[v] = t[left(v)] + t[right(v)];
    }
}

int64_t sum(vector<int>& t, int v, int l, int r, int ql, int qr)
{
    // cout << "CURRENT V: " << v << ", l: " << l << ", r: " << r << '\n';
    int64_t s = 0;
    if (r <= ql || l >= qr) {
        return 0;
    } else if (ql <= l && r <= qr) {
        return t[v];
    } else {
        int m = (r + l) / 2;
        return sum(t, left(v), l, m, ql, qr) + sum(t, right(v), m, r, ql, qr);
    }
}

void Solve()
{
    int n, k;
    cin >> n >> k;
    int tree_max_size = 1 << log(n);
    vector<int> t(2 * tree_max_size - 1); // init segment tree with zeros
    for (int j = 0; j < k; ++j) {
        char command;
        cin >> command;
        if (command == 'A') {
            int i;
            int x;
            cin >> i >> x;
            update(t, 0, 0, tree_max_size, i-1, x);
            // for (const auto e : t) {
            //     cout << e << ' ';
            // }
            // cout << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            cout << sum(t, 0, 0, tree_max_size, l-1, r) << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solve();
    return 0;
}