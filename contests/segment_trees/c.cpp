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
    int gcd;

    Node(int gcd) : gcd(gcd) {};
};

int Left(int v)
{
    return 2 * v + 1;
}

int Right(int v)
{
    return 2 * v + 2;
}

int GCD(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return max(a, b);
}

Node Merge(Node left, Node right)
{   
    return Node(GCD(left.gcd, right.gcd));
} 

void Update(vector<Node>& t, int v, int l, int r, int pos, int x)
{
    if (r - l == 1) {
        t[v] = Node(x);
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

Node GetGCD(vector<Node>& t, int v, int l, int r, int ql, int qr)
{
    if (r <= ql || qr <= l) {
        return Node(-1);
    } else if (ql <= l && r <= qr) {
        return t[v];
    } else {
        int m = (l + r) / 2;
        return Merge(
            GetGCD(t, Left(v), l, m, ql, qr),
            GetGCD(t, Right(v), m, r, ql, qr)
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
    vector<Node> t(2 * tree_size - 1, Node(-1));
    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        Update(t, 0, 0, tree_size, i, e);
    }
    int k;
    cin >> k;
    while (k--) {
        int ql, qr;
        cin >> ql >> qr;
        cout << GetGCD(t, 0, 0, tree_size, ql-1, qr).gcd << ' ';
    }

    return 0;
}