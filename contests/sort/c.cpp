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

vector<int32_t> MaxGold(vector<int32_t>& a, vector<int32_t>& d, vector<int32_t>& g)
{
    vector<int32_t> max_gold(a.size());
    
    vector<int> idx_a(a.size());
    iota(idx_a.begin(), idx_a.end(), 0);
    stable_sort(idx_a.begin(), idx_a.end(),
        [&a](size_t i1, size_t i2) {return a[i1] < a[i2];});
    // cout << idx_a << '\n';
    vector<int> idx(d.size());
    iota(idx.begin(), idx.end(), 0);
    stable_sort(idx.begin(), idx.end(),
        [&d](size_t i1, size_t i2) {return d[i1] < d[i2];});
    // cout << idx << '\n';
    int32_t s = 0;
    int i = 0, j = 0;
    while (i < a.size()) {
        // cout << "i=" << i << ",idx=" << idx_a[i] << ",j=" << j << ",idx=" << idx[j] << ",s=" << s << '\n';
        if (j < d.size() && a[idx_a[i]] >= d[idx[j]]) {
            s += g[idx[j]];
            ++j;
        } else {
            max_gold[idx_a[i]] = s;
            ++i;
        }
    }
    return max_gold;
}

int main()
{
    int s, b;
    cin >> s >> b;
    vector<int32_t> a(s);
    cin >> a;
    vector<int32_t> d(b), g(b); 
    for (int i = 0; i < b; ++i) {
        cin >> d[i] >> g[i];
    }
    cout << MaxGold(a, d, g) << '\n';

    return 0;
}