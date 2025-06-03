#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

struct Node {
    vector<int64_t> number;
    vector<int> replace;
    Node() {
        number = vector<int64_t>(10, 0);
        replace = vector<int>(10);
        iota(replace.begin(), replace.end(), 0);
    }
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
    for (int i = 0; i < t[v].replace.size(); ++i) {
        int j = t[v].replace[i];
        if (j != i) {
            if (r - l > 1) {
                t[Left(v)].replace[i] = j;
                t[Right(v)].replace[i] = j;
            }
            t[v].number[j] += t[v].number[i];
            t[v].number[i] = 0;
            t[v].replace[i] = i;
        }
    }
}

vector<int64_t> Merge(vector<int64_t> left, vector<int64_t> right)
{
    for (int i = 0; i < left.size(); ++i) {
        left[i] += right[i];       
    }
    return left;
}

void Add(vector<Node>& t, int v, int l, int r, int ql, int qr, int x, int y)
{
    Push(t, v, l, r);
    if (r <= ql || qr <= l) {
        return;
    } else if (ql <= l && r <= qr) {
        t[v].replace[x] = y;
        Push(t, v, l, r);
    } else {
        int m = (l + r) / 2;
        Add(t, Left(v), l, m, ql, qr, x, y);
        Add(t, Right(v), m, r, ql, qr, x, y);
        t[v].number = Merge(t[Left(v)].number, t[Right(v)].number);
    }
}

int64_t TransformNumber(vector<int64_t> number)
{
    int64_t sum = 0;
    for (int64_t i = 0; i < number.size(); ++i) {
        sum += i * number[i];
    }
    return sum;
}

vector<int64_t> ParseNumber(int64_t number)
{
    vector<int64_t> repr(10);
    int64_t i = 1;
    while (number > 0) {
        repr[number % 10] += i;
        number = number / 10;
        i *= 10;
    }
    return repr;
}

int64_t Get(vector<Node>& t, int v, int l, int r, int ql, int qr)
{
    Push(t, v, l, r);
    if (r <= ql || qr <= l) {
        return 0;
    } else if (ql <= l && r <= qr) {
        return TransformNumber(t[v].number);
    } else {
        int m = (l + r) / 2;
        return Get(t, Left(v), l, m, ql, qr) + Get(t, Right(v), m, r, ql, qr);
    }
}

int Log(int n)
{
    int res = 1, power = 0;
    while (n > res) {
        ++power;
        res *= 2;
    }
    return power;
}

void Build(vector<Node>& t, vector<int64_t>& a, int v, int l, int r)
{
    if (r - l == 1) {
        if (l < a.size()) {
            t[v].number = ParseNumber(a[l]);
        }
    } else {
        int m = (l + r) / 2;
        Build(t, a, Left(v), l, m);
        Build(t, a, Right(v), m, r);
        t[v].number = Merge(t[Left(v)].number, t[Right(v)].number);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    int tree_size = (1 << Log(n));
    vector<Node> t(2 * tree_size - 1, Node());
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Build(t, a, 0, 0, tree_size);

    while (q--) {
        int command;
        cin >> command;
        if (command == 1) {
            int ql, qr, x, y;
            cin >> ql >> qr >> x >> y;
            Add(t, 0, 0, tree_size, ql-1, qr, x, y);
        } else {
            int ql, qr;
            cin >> ql >> qr;
            cout << Get(t, 0, 0, tree_size, ql-1, qr) << '\n';
        }
    }
    

    return 0;
}