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

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        cin >> v;

        int i = 0;
        while (i < n-1 && k > 0) {
            if (v[i] == 0) {
                ++i;
                continue;
            }
            --v[i];
            ++v[n-1];
            --k;
        }
        cout << v << '\n';
    }

    return 0;
}