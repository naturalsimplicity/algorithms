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
    int x;
    Node(int x) : x(x) {};
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
    if (left.x != -1) {
        return left;
    } else {
        return right;
    }
}

void Build(vector<Node>& t, int v, int l, int r, int n)
{
    if (r - l == 1) {
        if (l < n) {
            t[v] = Node(l);
        } else {
            t[v] = Node(-1);
        }
    } else {
        int m = (l + r) / 2;
        Build(t, Left(v), l, m, n);
        Build(t, Right(v), m, r, n);
        t[v] = Merge(t[Left(v)], t[Right(v)]);
    }
}

void Exit(vector<Node>& t, int v, int l, int r, int x)
{
    if (r - l == 1) {
        t[v] = Node(l);
    } else {
        int m = (l + r) / 2;
        if (x < m) {
            Exit(t, Left(v), l, m, x);
        } else {
            Exit(t, Right(v), m, r, x);
        }
        t[v] = Merge(t[Left(v)], t[Right(v)]);
    }
}

int Enter(vector<Node>& t, int v, int l, int r, int x)
{
    if (x >= r) {
        return -1;
    } else if (r - l == 1) {
        if (t[v].x != -1 && x <= l) {
            t[v] = Node(-1); // occupy the parking
            return l;
        }
        return -1;
    } else {
        int m = (l + r) / 2;
        if (t[Left(v)].x != -1) { // check if segment has at least one free parking
            int left = Enter(t, Left(v), l, m, x);
            if (left != -1) { // check, that x is in required segment
                t[v] = Merge(t[Left(v)], t[Right(v)]);
                return left;
            }
        }
        if (t[Right(v)].x != -1) {
            int right = Enter(t, Right(v), m, r, x);
            if (right != -1) {
                t[v] = Merge(t[Left(v)], t[Right(v)]);
            }
            return right;
        }
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int tree_size = (1 << Log(n));
    vector<Node> t(2 * tree_size - 1, Node(-1));
    Build(t, 0, 0, tree_size, n);

    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        if (s == "enter") {
            // for (int j = 0; j < t.size(); ++j) {
            //     cout << t[j].x << ' ';
            // }
            // cout << '\n';
            int res = Enter(t, 0, 0, tree_size, x - 1);
            if (res == -1) {
                res = Enter(t, 0, 0, tree_size, 0);
            }
            cout << res + 1 << '\n';
        } else {
            Exit(t, 0, 0, tree_size, x - 1);
        }
    }

    return 0;
}
