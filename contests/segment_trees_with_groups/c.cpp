// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>

// using namespace std;

// int Log(int n)
// {
//     int res = 1, power = 0;
//     while (n > res) {
//         ++power;
//         res *= 2;
//     }
//     return power;
// }

// struct Node {
//     int max;
//     int add;
// };

// int Left(int v)
// {
//     return 2 * v + 1;
// }

// int Right(int v)
// {
//     return 2 * v + 2;
// }

// void Push(vector<Node>& t, int v, int l, int r)
// {
//     if (t[v].add != 0) {
//         if (r - l > 1) {
//             t[Left(v)].add += t[v].add;
//             t[Right(v)].add += t[v].add;
//         }
//         t[v].max += t[v].add;
//         t[v].add = 0;
//     }
// }

// void Add(vector<Node>& t, int v, int l, int r, int ql, int qr, int x)
// {
//     Push(t, v, l, r); // push in subtrees when access values (on premise)
//     if (r <= ql || qr <= l) {
//         return;
//     } else if (ql <= l && r <= qr) {
//         t[v].add += x;
//         Push(t, v, l, r); // push in subtree to update sum value
//     } else {
//         int m = (l + r) / 2;
//         Add(t, Left(v), l, m, ql, qr, x);
//         Add(t, Right(v), m, r, ql, qr, x);
//         if (t[Left(v)].max >= t[Right(v)].max) {
//             t[v].max = t[Left(v)].max;
//         } else {
//             t[v].max = t[Right(v)].max;
//         }
//     }
// }

// pair<int, int> Max(vector<Node>& t, int v, int l, int r)
// {
//     Push(t, v, l, r);
//     if (r - l == 1) {
//         return pair<int, int>(t[v].max, l);
//     } else {
//         int m = (l + r) / 2;
//         if (t[Left(v)].max >= t[Right(v)].max) {
//             return Max(t, Left(v), l, m);
//         } else {
//             return Max(t, Right(v), m, r);
//         }
//     }
// }

// struct Event {
//     int x;
//     int add;
//     int y1;
//     int y2;

//     bool operator< (const Event& e) const {
//         if (x != e.x) return x < e.x;
//         if (add != e.add) return add > e.add;
//         if (y1 != e.y1) return y1 < e.y1;
//         return y2 < e.y2;
//     }
// };

// int main()
// {
//     // OX: scanline
//     // OY: segment tree
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;

//     const int COORDINATE_MAX_VALUE = 2*1e5;

//     int tree_size = (1 << Log(2 * COORDINATE_MAX_VALUE + 1)); // |x| <= 2*1e5, +1 for zero
//     // segment tree
//     vector<Node> t(2 * tree_size - 1, Node{});

//     // scanline events
//     vector<Event> e;
//     for (int i = 0; i < n; ++i) {
//         int x1, y1, x2, y2;
//         cin >> x1 >> y1 >> x2 >> y2;
//         e.push_back(Event{x1, 1, y1, y2});
//         e.push_back(Event{x2, -1, y1, y2});
//     }
//     sort(e.begin(), e.end());

//     int node_max = 0;
//     int node_x = 0;
//     int node_y = 0;
//     for (int i = 0; i < e.size(); ++i) {
//         Add(t, 0, 0, tree_size, e[i].y1+COORDINATE_MAX_VALUE, e[i].y2+COORDINATE_MAX_VALUE+1, e[i].add);
//         if (e[i].add == 1) {
//             auto m = Max(t, 0, 0, tree_size);
//             if (m.first > node_max) {
//                 node_max = m.first;
//                 node_x = e[i].x;
//                 node_y = m.second - COORDINATE_MAX_VALUE;
//             }
//         }
//     }

//     cout << node_max << '\n';
//     cout << node_x << ' ' << node_y << '\n';

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Event {
    int x;
    int type;
    int y1, y2;
    Event(int x, int type, int y1, int y2) : x(x), type(type), y1(y1), y2(y2) {}
    bool operator<(const Event& other) const {
        if (x != other.x) return x < other.x;
        return type > other.type;
    }
};

struct SegmentTree {
    int size;
    vector<int> max_val;
    vector<int> add;

    SegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        max_val.assign(2 * size, 0);
        add.assign(2 * size, 0);
    }

    void push(int node, int left, int right) {
        if (add[node] == 0) return;
        max_val[node] += add[node];
        if (left != right) {
            add[2 * node] += add[node];
            add[2 * node + 1] += add[node];
        }
        add[node] = 0;
    }

    void update(int l, int r, int val, int node, int node_l, int node_r) {
        push(node, node_l, node_r);
        if (r < node_l || l > node_r) return;
        if (l <= node_l && node_r <= r) {
            add[node] += val;
            push(node, node_l, node_r);
            return;
        }
        int mid = (node_l + node_r) / 2;
        update(l, r, val, 2 * node, node_l, mid);
        update(l, r, val, 2 * node + 1, mid + 1, node_r);
        max_val[node] = max(max_val[2 * node], max_val[2 * node + 1]);
    }

    void update(int l, int r, int val) {
        update(l, r, val, 1, 0, size - 1);
    }

    int query_max() {
        push(1, 0, size - 1);
        return max_val[1];
    }

    int query_pos(int node, int node_l, int node_r) {
        push(node, node_l, node_r);
        if (node_l == node_r) return node_l;
        int mid = (node_l + node_r) / 2;
        push(2 * node, node_l, mid);
        push(2 * node + 1, mid + 1, node_r);
        if (max_val[node] == max_val[2 * node]) {
            return query_pos(2 * node, node_l, mid);
        } else {
            return query_pos(2 * node + 1, mid + 1, node_r);
        }
    }

    int query_pos() {
        return query_pos(1, 0, size - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Event> events;
    vector<int> ys;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 > y2) swap(y1, y2);
        events.emplace_back(x1, 1, y1, y2);
        events.emplace_back(x2, -1, y1, y2);
        ys.push_back(y1);
        ys.push_back(y2);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int y_size = ys.size();

    auto get_compressed = [&](int y) {
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
    };

    for (auto& e : events) {
        e.y1 = get_compressed(e.y1);
        e.y2 = get_compressed(e.y2);
    }

    sort(events.begin(), events.end());

    SegmentTree st(y_size);

    int max_overlap = 0;
    int best_x = 0, best_y = 0;

    for (int i = 0; i < events.size(); ) {
        int current_x = events[i].x;
        int j = i;
        while (j < events.size() && events[j].x == current_x && events[j].type == 1) {
            st.update(events[j].y1, events[j].y2, 1);
            ++j;
        }

        int current_max = st.query_max();
        if (current_max > max_overlap) {
            max_overlap = current_max;
            best_x = current_x;
            best_y = st.query_pos();
        }

        while (j < events.size() && events[j].x == current_x) {
            st.update(events[j].y1, events[j].y2, -1);
            ++j;
        }

        i = j;
    }

    cout << max_overlap << "\n";
    cout << best_x << " " << ys[best_y] << "\n";

    return 0;
}