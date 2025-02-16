#include <iostream>
#include <vector>
#include <map>
#include <set>
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

int32_t MaxSize(vector<int>& a, int n)
{
    map<int, int> m;
    for (int x : a) {
        ++m[x];
    }
    vector<int> v;
    for (auto& x : m) {
        // cout << x.first << ": " << x.second << '\n';
        v.push_back(x.second);
    }
    sort(v.begin(), v.end());
    int prev = v.back();
    int32_t sum = prev;
    int i = v.size()-2;
    while (i >= 0 && prev > 0) {
        // cout << "i=" << i << ", prev=" << prev << '\n';
        --prev;
        if (v[i] >= prev) {
            sum += prev;
            --i;
        }
    }
    return sum;
}

int main()
{
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        cin >> a;
        cout << MaxSize(a, n) << '\n';
    }
    return 0;
}