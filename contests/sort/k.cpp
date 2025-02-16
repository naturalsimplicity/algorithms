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

/* Critical test cases
IN
5 2
-1 -2 5 -4 8
OUT
15

IN
5 3
-1 -2 5 -4 8
OUT
23

suff
6 7 9 4 8

IN
7 6
-3 0 -1 -2 -2 -4 -1
OUT
-45

IN
4 1
3 -1 6 0
OUT
8

IN
6 3 
1 5 -5 100 10 20
OUT
391

suff
131 130 125 130 30 20
*/

int64_t MaxPrice(vector<int32_t>& a, int n, int k)
{
    int min_prefix_idx = 0;
    int64_t min_prefix_sum = a[0];
    int64_t prefix_sum = a[0];
    int64_t max_price = 0;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        // cout << "IN: " << "i=" << i << ", min_prefix_idx=" << min_prefix_idx 
        // << ", prefix_sum=" << prefix_sum << ", cnt=" << cnt << '\n';
        if (i < n - k + 1) {
            prefix_sum += a[i];
            if (prefix_sum < min_prefix_sum) {
                min_prefix_idx = i;
                min_prefix_sum = prefix_sum;
            }
        } else {
            max_price += cnt++ * min_prefix_sum;
            i = min_prefix_idx++;
            prefix_sum = 0;
            min_prefix_sum = a[i+1];
            --k;
        }
        // cout << "OUT: " << "i=" << i << ", min_prefix_idx=" << min_prefix_idx
        // << ", prefix_sum=" << prefix_sum << ", cnt=" << cnt << '\n';
    }
    max_price += cnt * prefix_sum;
    return max_price;
}

int64_t MaxPriceV2 (vector<int32_t>& a, int n, int k)
{
    int64_t max_price = 0;
    vector<int64_t> suffix_sums;
    reverse(a.begin(), a.end());
    suffix_sums.push_back(a[0]);
    for (int i = 1; i < n; ++i) {
        suffix_sums.push_back(suffix_sums[i-1] + a[i]);
    }
    // reverse(suffix_sums.begin(), suffix_sums.end());
    cout << suffix_sums << '\n';

    int i = 1;
    int max_suffix_i = 0;
    int64_t prev_max_suffix = 0;
    while (i < n) {
        cout << "IN: i=" << i << ", max_suffix_i=" << max_suffix_i << ", prev_max_suffix=" << prev_max_suffix << ", max_price=" << max_price <<  '\n'; 
        if (i < n - k + 1) {
            if (suffix_sums[i] > suffix_sums[max_suffix_i]) {
                max_suffix_i = i;
            }
        } else {
            max_price += k * (suffix_sums[max_suffix_i] - prev_max_suffix);
            prev_max_suffix = suffix_sums[max_suffix_i]; 
            --k;
            i = max_suffix_i;
            max_suffix_i = i + 1;
        }
        ++i;
        cout << "OUT: i=" << i << ", max_suffix_i=" << max_suffix_i << ", prev_max_suffix=" << prev_max_suffix << ", max_price=" << max_price <<  '\n'; 
    }
    max_price += k * (suffix_sums[n-1] - prev_max_suffix);

    return max_price;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int32_t> a(n);
    cin >> a;
    cout << MaxPriceV2(a, n, k) << '\n';
    return 0;
}