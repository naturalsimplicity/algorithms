#include <iostream>
#include <string>
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

// v = 2 2 2 2 2, x = 7, YES
// v = 3 3 6 3, x = 6, YES
// v = 2 3 5, x = 5, YES
// v = 4 5, x = 9, NO
// v = 1 1 1 1 1, x = 3, NO
// v = 1 4, x = 2, YES

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        cin >> v;
        sort(v.begin(), v.end());
        
        int sum = 0;
        bool is_one_unique = true;
        int a = v[0];
        for (auto& e : v) {
            sum += e;
            if (e != a) {
                is_one_unique = false;
            }
        }
        cout << "is_one_unique = " << is_one_unique << '\n';
        if (sum == x || is_one_unique && x % a == 0 && sum > x) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        int i = 0;
        sum = 0;
        while (i < n) {
            sum += v[i];
            if (sum < x) {
                ++i;
            } else if (sum == x) {
                i = 0;
                sum = 0;
                int last = v.back();
                v.pop_back();
                v.insert(v.begin(), last);
            } else {
                break;
            }
        }
        cout << v << '\n';
    }

    return 0;
}