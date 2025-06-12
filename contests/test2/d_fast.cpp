#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

int64_t CountValidPairs()
{
    int64_t n, x, y;
    cin >> n >> x >> y;
    vector<int64_t> v(n);

    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        int64_t a;
        cin >> a;
        v[i] = a;
        sum += a;
    }

    int64_t L = max(sum - y, 2LL), R = sum - x;
    if (R < L) {
        return 0;
    }
    sort(v.begin(), v.end());

    int64_t pairs = 0;
    for (int64_t i = 0; i < v.size(); ++i) {
        int64_t lb = L - v[i], ub = R - v[i];
        auto left = lower_bound(v.begin() + i + 1, v.end(), lb);
        auto right = upper_bound(v.begin() + i + 1, v.end(), ub);
        pairs += right - left;
    }
    return pairs;
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        cout << CountValidPairs() << '\n';
    }

    return 0;
}
