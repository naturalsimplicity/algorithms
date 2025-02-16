#include <iostream>
#include <vector>
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

int64_t MaxRemovedBlocks(vector<int32_t>& a, int n)
{
    int64_t r = 0;
    sort(a.begin(), a.end());
    int32_t m = a.back();
    int32_t reserve = a[0] - 1;
    for (int i = 1; i < n; ++i) {
        if (a[i-1] == a[i]) {
            if (reserve > 0) {
                ++r;
                --reserve;
            }
            r += a[i] - 1;
        } else {
            r += a[i-1];
            reserve += a[i] - a[i-1] - 1;
        }
    }
    return r;
}

int main()
{
    int32_t n, m;
    cin >> n >> m;
    vector<int32_t> a(n);
    cin >> a;
    cout << MaxRemovedBlocks(a, n) << '\n';

    return 0;
}