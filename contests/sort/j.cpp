#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename T>
istream& operator>>(istream& in, vector<T>& a)
{
    for (T& x : a) {
        in >> x;
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

int32_t MaxSplits(vector<int32_t>& a, int n, int B)
{
    vector<int32_t> possible_splits;
    int resid = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            ++resid;
        } else {
            --resid;
        }
        if (i < n-1 && i % 2 == 1 && resid == 0) {
            possible_splits.push_back(i);
        }
    }
    if (possible_splits.size() == 0) {
        return 0;
    }
    vector<int32_t> diffs;
    for (int32_t& i : possible_splits) {
        // cout << "i=" << i << '\n';
        diffs.push_back(abs(a[i] - a[i+1]));
    }
    vector<size_t> idx(possible_splits.size());
    iota(idx.begin(), idx.end(), 0);
    stable_sort(idx.begin(), idx.end(),
        [&diffs](size_t i1, size_t i2) {return diffs[i1] < diffs[i2];});
    // cout << "possible_splits: " << possible_splits << '\n';
    // cout << "diffs: " << diffs << '\n';
    // cout << "idx: " << idx << '\n';
    int32_t splits = 0;
    for (int i = 0; i < possible_splits.size(); ++i) {
        // cout << "idx=" << idx[i] << ",diff=" << diffs[idx[i]] << '\n';
        if (diffs[idx[i]] <= B) {
            ++splits;
            B -= diffs[idx[i]];
        } else {
            break;
        }
    }
    return splits;
}

int main()
{
    int32_t n, B;
    cin >> n >> B;
    vector<int32_t> a(n);
    cin >> a;
    cout << MaxSplits(a, n, B) << '\n';

    return 0;
}   