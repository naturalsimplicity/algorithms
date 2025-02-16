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

int64_t MinRemainingBacteries(vector<int32_t>& a, int n, int k)
{
    sort(a.begin(), a.end());
    int remaining = 0;
    int duplicates = 1;
    for (int i = 0; i < n-1; ++i) {
        if (a[i] == a[i+1]) {
            ++duplicates;
        } else {
            if (!(a[i] < a[i+1] && a[i+1] <= a[i] + k)) {
                remaining += duplicates;
            } 
            duplicates = 1;
        }
    }
    remaining += duplicates; // count last element(s)
    return remaining;
}

int main()
{
    int32_t n, k;
    cin >> n >> k;
    vector<int32_t> a(n);
    cin >> a;
    cout << MinRemainingBacteries(a, n, k) << '\n';

    return 0;
}   