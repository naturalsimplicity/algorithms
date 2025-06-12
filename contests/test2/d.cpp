#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

int CountValidPairs()
{
    int64_t n, x, y;
    cin >> n >> x >> y;
    vector<int32_t> v(n);
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }

    int32_t pairs = 0;
    int ptr1 = 0, ptr2 = 1;
    while (ptr1 < n && ptr2 < n) {
        int64_t curr = sum - v[ptr1] - v[ptr2];
        if (x <= curr && curr <= y) {
            ++pairs;
        }
        ++ptr2;
        if (ptr2 == n) {
            ++ptr1;
            ptr2 = ptr1 + 1;
        }
    }
    return pairs;
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        cout << CountValidPairs() << '\n';
    }

    return 0;
}
