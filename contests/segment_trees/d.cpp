#include <iostream>
#include <vector>
#include <algorithm>

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
    int x;
    int pos;
    Node(int pos, int x) : pos(pos), x(x) {};
};

int Left(int v)
{
    return 2 * v + 1;
}

int Right(int v)
{
    return 2 * v + 2;
}

Node Merge(Node left, Node right)
{   
    if (left.x >= right.x) {
        return left;
    } else {
        return right;
    };
} 

void Update(vector<Node>& t, int v, int l, int r, int pos, int x)
{
    if (r - l == 1) {
        t[v] = Node(pos, x);
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

Node Get2(vector<Node>& t, int v, int l, int r, int pos, int x)
{
    if (r <= pos || t[v].x < x) {
        return Node(-1, -1);
    } else if (r - l == 1) {
        return t[v];
    } else {
        int m = (l + r) / 2;
        if (t[Left(v)].x >= x) {
            Node left = Get2(t, Left(v), l, m, pos, x);
            if (left.x != -1) {
                return left;
            }
        }
        return Get2(t, Right(v), m, r, pos, x);
    }
}

Node Get(vector<Node>& t, int v, int l, int r, int pos, int x)
{
    if (pos >= r) {
        return Node(-1, -1);
    } else {
        if (t[v].x < x) {
            return Node(-1, -1);
        }
        if (r - l == 1) {
            if (t[v].x >= x && l >= pos) {
                return t[v];
            } else {
                return Node(-1, -1);
            }
        }
        int m = (l + r) / 2;
        if (t[Left(v)].x >= x) {
            Node left = Get(t, Left(v), l, m, pos, x);
            if (left.x != -1) {
                return left;
            }
        }
        return Get(t, Right(v), m, r, pos, x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int tree_size = (1 << Log(n));
    vector<Node> t(2 * tree_size - 1, Node(-1, -1));
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        Update(t, 0, 0, tree_size, i, e);
    }
    while (m--) {
        int r, i, x;
        cin >> r >> i >> x;
        if (r == 0) {
            Update(t, 0, 0, tree_size, i-1, x);
        } else {
            // for (int j = 0; j < t.size(); ++j) {
            //     cout << t[j].x << ' ';
            // }
            // cout << '\n';
            Node res = Get2(t, 0, 0, tree_size, i-1, x);
            cout << (res.pos == -1 ? -1 : res.pos + 1) << '\n';
        }
    }

    return 0;
}
