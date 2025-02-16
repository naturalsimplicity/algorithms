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

void GetDegenerateTriangle(vector<int32_t>& a, int n)
{
    if (a[0] > a[n-1] - a[1]) { // safe check of a[0] + a[1] > a[n-1]
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = n-1; k > j; --k) { // optimaze search of degenerate triangle
                if (a[i] <= a[k] - a[j]) { // safe check of a[i] + a[j] <= a[k]
                    cout << i+1 << ' ' << j+1 << ' ' << k+1 << '\n';
                    return;
                }
            }
        }
    }
    cout << -1 << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int32_t> a(n);
        cin >> a;
        GetDegenerateTriangle(a, n);
    }
    
    return 0;
}
