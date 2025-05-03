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
    long long rating;
    int zeros_left;
    int max_zeros;
    int zeros_right;

    Node(long long rating) : rating(rating) {
        int val = (rating == 0 ? 1 : 0);
        zeros_left = val;
        max_zeros = val;
        zeros_right = val;
    };

    Node() = default;
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
    Node node;
    if (left.zeros_right > 0 && right.zeros_left > 0
            && left.zeros_right + right.zeros_left > max(left.max_zeros, right.max_zeros)) {
        node.max_zeros = left.zeros_right + right.zeros_left;
    } else {
        node.max_zeros = max(left.max_zeros, right.max_zeros);
    }
    node.zeros_left = left.zeros_left;
    node.zeros_right = right.zeros_right;
    if (left.rating == 0) {
        node.zeros_left += right.zeros_left;
    }
    if (right.rating == 0) {
        node.zeros_right += left.zeros_right;
    }
    node.rating = abs(left.rating) + abs(right.rating);
    return node;
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

Node GetMaxZeros(vector<Node>& t, int v, int l, int r, int ql, int qr)
{
    if (r <= ql || qr <= l) {
        return Node();
    } else if (ql <= l && r <= qr) {
        return t[v];
    } else {
        int m = (l + r) / 2;
        Node left = GetMaxZeros(t, Left(v), l, m, ql, qr);
        Node right = GetMaxZeros(t, Right(v), m, r, ql, qr);
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
    vector<Node> t(2 * tree_size - 1, Node());

    for (int i = 0; i < n; ++i) {
        int e;
        cin >> e;
        Update(t, 0, 0, tree_size, i, e);
    }

    int m;
    cin >> m;
    while (m--) {
        string command;
        cin >> command;
        if (command == "QUERY") {
            int ql, qr;
            cin >> ql >> qr;
            cout << (GetMaxZeros(t, 0, 0, tree_size, ql-1, qr)).max_zeros << '\n';
        } else {
            int i, x;
            cin >> i >> x;
            Update(t, 0, 0, tree_size, i-1, x);
        }
    }

    return 0;
}
