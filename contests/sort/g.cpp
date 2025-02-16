#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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

string CheckMatrixTranspose(vector<vector<int32_t>>& a, vector<vector<int32_t>>& b)
{
    int n = a.size(), m = a[0].size();
    int i = 0, j = 0, k = 0;
    while (k < n + m - 1) {
        ++k;
        vector<int32_t> a_diag, b_diag;
        while (j >= 0 && i < n) {
            // cout << "i=" << i << ",j=" << j << '\n';
            a_diag.push_back(a[i][j]);
            b_diag.push_back(b[i][j]);
            ++i;
            --j;
        }
        // cout << "a_diag: " << a_diag << '\n';
        // cout << "b_diag: " << b_diag << '\n';
        sort(a_diag.begin(), a_diag.end());
        sort(b_diag.begin(), b_diag.end());
        if (a_diag != b_diag) {
            return "NO";
        }
        i = 0 + k - min(k, m-1);
        j = min(k, m-1);
    }
    return "YES";
}

int main()
{
    int32_t n, m;
    cin >> n >> m;
    vector<vector<int32_t>> a(n, vector<int32_t>(m)), b(n, vector<int32_t>(m));
    int i = 0;
    while (i < n) {
        cin >> a[i];
        ++i;
    }
    i = 0;
    while (i < n) {
        cin >> b[i];
        ++i;
    }
    cout << CheckMatrixTranspose(a, b) << '\n';
    return 0;
}