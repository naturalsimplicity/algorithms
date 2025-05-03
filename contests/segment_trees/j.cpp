#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
 
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
 
int Left(int v)
{
    return 2 * v + 1;
}
 
int Right(int v)
{
    return 2 * v + 2;
}
 
vector<int> Merge(vector<int> left, vector<int> right)
{   
    // vector stores ids of opened and yet not closed segments
    set<int> s;
    for (int i = 0; i < left.size(); ++i) {
        if (left[i] > 0) {
            s.insert(left[i]);
        } else {
            auto it = s.find(-left[i]);
            if (it != s.end()) {
                s.erase(it);
            } else {
                s.insert(left[i]);
            }
        }
    }
    for (int i = 0; i < right.size(); ++i) {
        if (right[i] > 0) {
            s.insert(right[i]);
        } else {
            auto it = s.find(-right[i]);
            if (it != s.end()) {
                s.erase(it);
            } else {
                s.insert(right[i]);
            }
        }
    }
 
    vector<int> node;
    for (auto it = s.begin(); it != s.end(); ++it) {
        node.push_back(*it);
    }
 
    return node;
}
 
void Update(vector<vector<int>>& t, int v, int l, int r, int id, int ql, int qr)
{
    if (r <= ql || qr < l) {
        return;
    } else if (r - l == 1) {
        if (ql == l) {
            t[v].push_back(id);
        } else if (qr == l) {
            t[v].push_back(-id);
        }
    } else {
        int m = (l + r) / 2;
        Update(t, Left(v), l, m, id, ql, qr);
        Update(t, Right(v), m, r, id, ql, qr);
        t[v] = Merge(t[Left(v)], t[Right(v)]);
    }
}
 
vector<int> GetSegmentIds(vector<vector<int>>& t, int v, int l, int r, int ql, int qr)
{
    if (r <= ql || qr <= l) {
        return vector<int>();
    } else if (ql <= l && r <= qr) {
        return t[v];
    } else {
        int m = (l + r) / 2;
        return Merge(
            GetSegmentIds(t, Left(v), l, m, ql, qr),
            GetSegmentIds(t, Right(v), m, r, ql, qr)
        );
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int tree_size = (1 << Log(1e6));
    vector<vector<int>> t(2 * tree_size - 1); // tree of differences
 
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int ql, qr;
        cin >> ql >> qr;
        Update(t, 0, 0, tree_size, i, ql-1, qr);
    }
    for (int j = 0; j < m; ++j) {
        set<int> segment_ids;
        int cnt;
        cin >> cnt;
        for (int k = 0; k < cnt; ++k) {
            int point;
            cin >> point;
            vector<int> ids = GetSegmentIds(t, 0, 0, tree_size, 0, point);
            for (auto it = ids.begin(); it != ids.end(); ++it) {
                // cout << "DEBUG: " << *it << '\n';
                segment_ids.insert(*it);
            }
        }
        cout << segment_ids.size() << '\n';
    }
    
    return 0;
}