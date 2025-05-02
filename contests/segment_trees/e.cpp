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
    int opening; // number of unmatched openning brackets
    int closing; // number of unmatched closing brackets
    int matched; // number of matched brackets
    Node(int opening, int closing, int matched) 
        : opening(opening), closing(closing), matched(matched) {};
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
    int merged = min(left.opening, right.closing);
    return Node(
        left.opening + right.opening - merged,
        left.closing + right.closing - merged,
        left.matched + right.matched + 2 * merged
    );
}

Node ParseBracket(char bracket)
{
    if (bracket == '(') {
        return Node(1, 0, 0);
    } else {
        return Node(0, 1, 0);
    }
}

void Build(vector<Node>&t, string& s, int v, int l, int r)
{
    if (r - l == 1) {
        if (l < s.size()) {
            t[v] = ParseBracket(s[l]);
        }
    } else {
        int m = (l + r) / 2;
        Build(t, s, Left(v), l, m);
        Build(t, s, Right(v), m, r);
        t[v] = Merge(t[Left(v)], t[Right(v)]);
    }
}

void Update(vector<Node>& t, int v, int l, int r, int pos, char bracket)
{
    if (r - l == 1) {
        t[v] = ParseBracket(bracket);
    } else {
        int m = (l + r) / 2;
        if (pos < m) {
            Update(t, Left(v), l, m, pos, bracket);
        } else {
            Update(t, Right(v), m, r, pos, bracket);
        }
        t[v] = Merge(t[Left(v)], t[Right(v)]);
    }
}

Node MaxSubsegmentLength(vector<Node>& t, int v, int l, int r, int ql, int qr)
{
    if (ql >= r || l >= qr) {
        return Node(0, 0, 0);
    } else if (ql <= l && r <= qr) {
        return t[v];
    } else {
        int m = (l + r) / 2;
        return Merge(
            MaxSubsegmentLength(t, Left(v), l, m, ql, qr),
            MaxSubsegmentLength(t, Right(v), m, r, ql, qr)
        );
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int tree_size = (1 << Log(s.size()));
    vector<Node> t(2 * tree_size - 1, Node(0, 0, 0));
    Build(t, s, 0, 0, tree_size);
    
    int m;
    cin >> m;
    while (m--) {
        int ql, qr;
        cin >> ql >> qr;
        cout << MaxSubsegmentLength(t, 0, 0, tree_size, ql-1, qr).matched << '\n';
    }

    return 0;
}
