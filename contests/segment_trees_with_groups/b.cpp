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
    int64_t sum;
    int64_t assign;
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
    if (t[v].assign != -1) {
        if (r - l > 1) {
            t[Left(v)].assign = t[v].assign;
            t[Right(v)].assign = t[v].assign;
        }
        t[v].sum = (r - l) * t[v].assign;
        t[v].assign = -1;
    }
}

void Add(vector<Node>& t, int v, int l, int r, int ql, int qr, int32_t x)
{
    Push(t, v, l, r);
    if (r <= ql || qr <= l) {
        return;
    } else if (ql <= l && r <= qr) {
        t[v].assign = x;
        Push(t, v, l, r);
    } else {
        int m = (l + r) / 2;
        Add(t, Left(v), l, m, ql, qr, x);
        Add(t, Right(v), m, r, ql, qr, x);
        t[v].sum = t[Left(v)].sum + t[Right(v)].sum;
    }
}

int64_t Sum(vector<Node>& t, int v, int l, int r, int ql, int qr)
{
    Push(t, v, l, r);
    if (r <= ql || qr <= l) {
        return 0;
    } else if (ql <= l && r <= qr) {
        return t[v].sum;
    } else {
        int m = (l + r) / 2;
        return Sum(t, Left(v), l, m, ql, qr) + Sum(t, Right(v), m, r, ql, qr);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int tree_size = (1 << Log(n));
    vector<Node> t(2 * tree_size - 1, Node{0, -1});

    while (k--) {
        string command;
        cin >> command;
        if (command == "Q") {
            int ql, qr;
            cin >> ql >> qr;
            cout << Sum(t, 0, 0, tree_size, ql-1, qr) << '\n';
        } else {
            int32_t ql, qr, x;
            cin >> ql >> qr >> x;
            Add(t, 0, 0, tree_size, ql-1, qr, x);
        }
    }

    return 0;
}
