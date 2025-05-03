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
    vector<int32_t> segment;
    vector<int64_t> left_greater;
    vector<int64_t> right_lower;

    Node(int32_t value) {
        segment.push_back(value);
        left_greater.push_back(0);
        right_lower.push_back(0);
    }

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
    Node node{};

    int i = 0, j = 0;
    while (i < left.segment.size() || j < right.segment.size()) {
        if (i == left.segment.size() || j < right.segment.size() && left.segment[i] > right.segment[j]) {
            node.segment.push_back(right.segment[j]);
            node.left_greater.push_back(left.segment.size() - i + right.left_greater[j]);
            node.right_lower.push_back(right.right_lower[j]);
            ++j;
        } else {
            node.segment.push_back(left.segment[i]);
            node.left_greater.push_back(left.left_greater[i]);
            node.right_lower.push_back(j + left.right_lower[i]);
            ++i;
        }
    }

    // only to pass the 21st test with memory limit
    left.left_greater.clear();
    left.left_greater.shrink_to_fit();
    left.right_lower.clear();
    left.right_lower.shrink_to_fit();

    right.left_greater.clear();
    right.left_greater.shrink_to_fit();
    right.right_lower.clear();
    right.right_lower.shrink_to_fit();

    return node;
}

void Build(vector<Node>& t, vector<int32_t>& a, int v, int l, int r)
{
    if (r - l == 1) {
        if (l < a.size()) {
            t[v] = Node(a[l]);
        }
    } else {
        int m = (l + r) / 2;
        Build(t, a, Left(v), l, m);
        Build(t, a, Right(v), m, r);
        t[v] = Merge(t[Left(v)], t[Right(v)]);
    }
}

int64_t DotProduct(vector<int64_t>& a, vector<int64_t>& b)
{
    int size = min(a.size(), b.size());
    int64_t product = 0;
    for (int i = 0; i < size; ++i) {
        product += a[i] * b[i];
    }
    return product;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int tree_size = (1 << Log(n));
    vector<Node> t(2 * tree_size - 1);

    vector<int32_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Build(t, a, 0, 0, tree_size);

    cout << DotProduct(t[0].left_greater, t[0].right_lower) << '\n';

    // for (int i = 0; i < n; ++i) {
    //     cout << t[0].inversions[i] << ' ';
    // }
    // cout << '\n';
    
    return 0;
}
