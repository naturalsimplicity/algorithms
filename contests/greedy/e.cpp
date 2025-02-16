#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
istream& operator>>(istream& in, vector<T>& a)
{
    for (T& x : a) {
        in >> x;
    }
    return in;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    cin >> a;
    cin >> b;

    bool is_asc = true;
    int zeros = 0;
    int prev = -1;
    int first_zero_idx = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0 && a[i] < prev) {
            is_asc = false;
        }
        if (a[i] == 0) {
            if (zeros == 0) {
                first_zero_idx = i;
            }
            ++zeros;
        } else {
            prev = a[i];
        }
    }
    // cout << "is_asc=" << is_asc << ",zeros=" << zeros << ",first_zero_idx=" << first_zero_idx << '\n';
    if (zeros == 1 && is_asc) {
        if (first_zero_idx == 0 && b[0] < a[1] || 
            first_zero_idx == n-1 && b[0] > a[n-2] ||
            first_zero_idx > 0 && first_zero_idx < n-1 &&
            a[first_zero_idx-1] < b[0] && a[first_zero_idx+1] > b[0]
        ) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    } else {
        cout << "YES" << '\n';
    }

    
    return 0;
}