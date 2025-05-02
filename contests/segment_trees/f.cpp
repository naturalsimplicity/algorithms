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
    vector<int64_t> segment; // sorted segment
    vector<int64_t> inversions; // vector of inversions for each element
    int64_t triple_inversions; // number of triple inversions
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
    node.triple_inversions = left.triple_inversions + right.triple_inversions;
    int i = 0, j = 0;
    vector<int64_t> postfix_left_inversions(left.inversions.size());

    for (int k = left.inversions.size() - 1; k >= 0; --k) {
        if (k == left.inversions.size() - 1) {
            postfix_left_inversions[k] = left.inversions[k];
        } else {
            postfix_left_inversions[k] = postfix_left_inversions[k+1] + left.inversions[k];
        }
    }
    
    while (i < left.segment.size() && j < right.segment.size()) {
        if (left.segment[i] > right.segment[j]) { // i == left.segment.size() || j < right.segment.size() && 
            node.triple_inversions += postfix_left_inversions[i];
            node.segment.push_back(right.segment[j]);
            node.inversions.push_back(left.segment.size() - i + right.inversions[j]);
            ++j;
        } else {
            node.segment.push_back(left.segment[i]);
            node.inversions.push_back(0 + left.inversions[i]);
            ++i;
        }
    }

    while (i < left.segment.size()) {
        node.segment.push_back(left.segment[i]);
        node.inversions.push_back(left.inversions[i]);
        ++i;
    }

    while (j < right.segment.size()) {
        node.segment.push_back(right.segment[j]);
        node.inversions.push_back(right.inversions[j]);
        ++j;
    }

    return node;
}

void Build(vector<Node>& t, vector<int64_t>& a, int v, int l, int r)
{
    if (r - l == 1) {
        if (l < a.size()) {
            t[v].segment.push_back(a[l]);
            t[v].inversions.push_back(0);
        }
    } else {
        int m = (l + r) / 2;
        Build(t, a, Left(v), l, m);
        Build(t, a, Right(v), m, r);
        t[v] = Merge(t[Left(v)], t[Right(v)]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int tree_size = (1 << Log(n));
    vector<Node> t(2 * tree_size - 1);

    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Build(t, a, 0, 0, tree_size);

    cout << t[0].triple_inversions << '\n';

    for (int i = 0; i < n; ++i) {
        cout << t[0].inversions[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
