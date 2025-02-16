#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

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

int32_t MaxMedian(vector<int32_t>& a, int n, int k)
{
    int m = n / 2;
    sort(a.begin(), a.end());
    int i = m;
    while (k > 0) {
        while (i < n - 1 && a[i] == a[i + 1]) {
            ++i;
            if (i - m >= k) {
                return a[i];
            }
        }
        ++a[i];
        if (i > m) {
            --i;
        }
        --k;
    }
    return a[m];
}

int32_t MaxMedian2(vector<int32_t>& a, int n, int k)
{
    int m = n / 2;
    sort(a.begin(), a.end());
    int32_t max_median = a[m];
    int cnt = 1;
    for (int i = m; i < n-1; ++i) {
        int32_t diff = a[i+1] - a[i];
        if (diff > 0) {
            // cout << "s=" << s << ", cnt=" << cnt << ", i=" << i << '\n';
            if (diff >= numeric_limits<int32_t>::max() / cnt || diff * cnt >= k) {
                return max_median + k / cnt;
            }
            max_median += diff;
            k -= diff * cnt;
        }
        ++cnt;
    }
    return max_median + k / cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int32_t> a(n);
    cin >> a;
    int32_t median = MaxMedian2(a, n, k);
    cout << median << '\n';
    // cout << a << '\n';
    // 1 1 1 1 1 2 2 3 4, k = 8 -> 4
    // 1 1 1 1 1 2 2 3 4, k = 13 -> 5
    return 0;
}