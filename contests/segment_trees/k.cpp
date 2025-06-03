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
    int32_t even;
    int32_t odd;

    Node(int32_t even, int32_t odd) : even(even), odd(odd) {};
};

int Left(int v)
{
    return 2 * v + 1;
}

int Right(int v)
{
    return 2 * v + 2;
}

Node Merge(Node& left, Node& right)
{
    return Node(left.even + right.even, left.odd + right.odd);
}

void Update(vector<Node>& t, int v, int l, int r, int pos, int x)
{
    if (r - l == 1) {
        if (pos % 2 == 0) {
            t[v] = Node(x, -x);
        } else {
            t[v] = Node(-x, x);
        }
    } else {
        int m = (l + r) / 2;
        if (pos < m) {
            Update(t, Left(v), l, m, pos, x);
        } else {
            Update(t, Right(v), m, r, pos, x);
        }
        t[v] = Merge(t[Left(v)], t[Right(v)]);
    }
}

Node Sum(vector<Node>& t, int v, int l, int r, int ql, int qr)
{
    if (r <= ql || qr <= l) {
        return Node(0, 0);
    } else if (ql <= l && r <= qr) {
        return t[v];
    } else {
        int m = (l + r) / 2;
        Node left = Sum(t, Left(v), l, m, ql, qr);
        Node right = Sum(t, Right(v), m, r, ql, qr);
        return Merge(left, right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int tree_size = (1 << Log(n));
    vector<Node> t(2 * tree_size - 1, Node(0, 0));

    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        Update(t, 0, 0, tree_size, i, e);
    }

    int m;
    cin >> m;
    while (m--) {
        int command;
        cin >> command;
        if (command == 0) {
            int32_t i, j;
            cin >> i >> j;
            Update(t, 0, 0, tree_size, i-1, j);
        } else {
            int l, r;
            cin >> l >> r;
            Node result = Sum(t, 0, 0, tree_size, l-1, r);
            if ((l-1) % 2 == 0) {
                cout << result.even << '\n';
            } else {
                cout << result.odd << '\n';
            }
        }
    }

    return 0;
}
