#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;

// THIS CODE CAUSES OUT OF MEMORY!

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
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

int Left(int v)
{
    return 2 * v + 1;
}

int Right(int v)
{
    return 2 * v + 2;
}

void Push(vector<int>& t, int v, int l, int r)
{
    if (t[v] != 0) {
        if (r - l > 1) {
            t[Left(v)] = t[v];
            t[Right(v)] = t[v];
            t[v] = 0;
        }
    }
}

void Add(vector<int>& t, int v, int l, int r, int ql, int qr, int x)
{
    Push(t, v, l, r);
    if (r <= ql || qr <= l) {
        return;
    } else if (ql <= l && r <= qr) {
        t[v] = x;
        Push(t, v, l, r);
    } else {
        int m = (l + r) / 2;
        Add(t, Left(v), l, m, ql, qr, x);
        Add(t, Right(v), m, r, ql, qr, x);
        t[v] = 0; // set to undefined
    }
}

int Get(vector<int>& t, int v, int l, int r, int x) 
{
    Push(t, v, l, r);
    if (r - l == 1) {
        return t[v]; // can be equal to 0 if not painted yet
    } else if (l <= x && x < r && t[v] != 0) {
        return t[v];
    } else {
        int m = (l + r) / 2;
        if (x < m) {
            return Get(t, Left(v), l, m, x);
        } else {
            return Get(t, Right(v), m, r, x);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    int tree_size = (1 << Log(n));
    vector<int> t(2LL * tree_size - 1); // zeros by default

    while (m--) {
        int c, ql, qr;
        cin >> c >> ql >> qr;
        Add(t, 0, 0, tree_size, ql-1, qr, c);
    }

    vector<int> cnt(k+1);
    for (int i = 0; i < n; ++i) {
        ++cnt[Get(t, 0, 0, tree_size, i)];
    }

    for (int i = 1; i < k+1; ++i) {
        cout << cnt[i] << ' ';
    }
    cout << '\n';
    // cout << "DEBUG (tree): " << t << '\n';

    return 0;
}
