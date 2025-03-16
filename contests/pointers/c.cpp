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

int MaxPairs(vector<int>& a, vector<int>& b, int n, int m)
{
    int max_pairs = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] - b[j] > 1) {
            ++j;
        } else if (b[j] - a[i] > 1) {
            ++i;
        } else {
            ++max_pairs;
            ++i;
            ++j;
        }
    }
    return max_pairs;
}


int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    cin >> m;
    vector<int> b(m);
    cin >> b;
    cout << MaxPairs(a, b, n, m) << '\n';
    
    return 0;
}
