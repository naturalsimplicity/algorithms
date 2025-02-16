#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

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

int32_t MinPrice(vector<int32_t>& a, int n, int k)
{
    vector<int32_t> v(n);
    v[0] = 0;
    for (int i = 1; i < n; ++i) {
        v[i] = a[i] - a[i-1];
    }

    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);

    stable_sort(idx.begin(), idx.end(),
        [&v](size_t i1, size_t i2) {return v[i1] >= v[i2];});
    vector<bool> vs(n);
    for (int j = 0; j < k - 1; ++j) {
        vs[idx[j]] = true;
    }
    // cout << "vs=" << vs << '\n';
    int32_t min_price = 0, left = a[0], right = a[0];
    for (int i = 0; i < n; ++i) {
        // cout << "left=" << left << ", right=" << right << '\n';
        if (vs[i]) {
            min_price += right - left;
            left = a[i];
        }
        right = a[i];
    }
    min_price += right - left;
    return min_price;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int32_t> a(n);
    cin >> a;
    cout << MinPrice(a, n, k) << '\n';

    return 0;
}