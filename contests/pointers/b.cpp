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

int64_t MaxDegreeOfFriendship(vector<int>& m, vector<int>& s, int n, int d)
{
    int i = 0, j = 0;
    int64_t max_degree_of_friendship = 0;
    int64_t current_friendship = 0;
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
        [&m](int i1, int i2) {return m[i1] < m[i2];});
    
    while (i < n && j < n) {
        if (m[idx[j]] - m[idx[i]] < d) {
            current_friendship += s[idx[j]];
            ++j;
        } else {
            current_friendship -= s[idx[i]];
            ++i;
        }
        if (current_friendship > max_degree_of_friendship) {
            max_degree_of_friendship = current_friendship;
        }
    }
    return max_degree_of_friendship;
}


int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> m(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i] >> s[i];
    }
    cout << MaxDegreeOfFriendship(m, s, n, d) << '\n';
    return 0;
}
