#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Log(int n)
{
    int res = 1, power = 0;
    while (n > res) {
        ++power;
        res *= 2;
    }
    return power;
}

struct Node {
    int64_t max;
    int64_t add;
};

int Left(int v)
{
    return 2 * v + 1;
}

int Right(int v)
{
    return 2 * v + 2;
}

void Push(vector<Node>& t, int v, int l, int r)
{
    if (t[v].add != 0) {
        if (r - l > 1) {
            t[Left(v)].add += t[v].add;
            t[Right(v)].add += t[v].add;
        }
        t[v].max += t[v].add;
        t[v].add = 0;
    }
}

void Add(vector<Node>& t, int v, int l, int r, int ql, int qr, int32_t x)
{
    Push(t, v, l, r); // push in subtrees when access values (on premise)
    if (r <= ql || qr <= l) {
        return;
    } else if (ql <= l && r <= qr) {
        t[v].add += x;
        Push(t, v, l, r); // push in subtree to update sum value
    } else {
        int m = (l + r) / 2;
        Add(t, Left(v), l, m, ql, qr, x);
        Add(t, Right(v), m, r, ql, qr, x);
        t[v].max = max(t[Left(v)].max, t[Right(v)].max);
    }
}

int64_t Max(vector<Node>& t, int v, int l, int r, int ql, int qr)
{
    Push(t, v, l, r);
    if (r <= ql || qr <= l) {
        return 0;
    } else if (ql <= l && r <= qr) {
        return t[v].max;
    } else {
        int m = (l + r) / 2;
        return max(
            Max(t, Left(v), l, m, ql, qr),
            Max(t, Right(v), m, r, ql, qr)
        );
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int tree_size = (1 << Log(n));
    vector<Node> t(2 * tree_size - 1, Node{});

    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        Add(t, 0, 0, tree_size, i, i+1, e);
    }

    int m;
    cin >> m;
    while (m--) {
        string command;
        cin >> command;
        if (command == "m") {
            int ql, qr;
            cin >> ql >> qr;
            cout << Max(t, 0, 0, tree_size, ql-1, qr) << '\n';
        } else {
            int32_t ql, qr, x;
            cin >> ql >> qr >> x;
            Add(t, 0, 0, tree_size, ql-1, qr, x);
        }
    }

    return 0;
}
