#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>

using namespace std;

template<typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) {
        in >> x;
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a) {
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

int64_t CountSubvectors(vector<int32_t>& a, int32_t n, int32_t k)
{
    int64_t count = 0;
    int left = 0, right = 0;
    map<int, deque<int>> q;

    bool enough_doubles = false;
    while (right < n) {
        int el = a[right];
        // cout << "left=" << left << ",right=" << right << ", q[right].size()=" << q[el].size() << '\n';
        q[el].push_back(right);
        if (q[el].size() >= k) {
            enough_doubles = true;
            left = max(left, q[el].front());
            q[el].pop_front();
        }
        if (enough_doubles) {
            count += left + 1;
        }
        ++right;
        // cout << "left=" << left << ",right=" << right << ",count=" << count << '\n';
    }
    
    return count;
}

int main() {
    int32_t n, k;
    cin >> n >> k;
    vector<int32_t> a(n);
    cin >> a;
    cout << CountSubvectors(a, n, k) << '\n';
    return 0;
}
