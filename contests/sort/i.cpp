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

int64_t MaxScoreDiff(vector<int32_t>& va, vector<int32_t>& vb)
{
    int64_t A = 0, B = 0;
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    int i = va.size()-1, j = vb.size()-1;
    while (i >= 0 || j >= 0) {
        if (j < 0 || va[i] - vb[j] >= 0 && i >= 0) {
            // cout << "Add " << va[i] << " to A" << '\n';
            A += va[i];
            --i;
        } else {
            // cout << "Remove " << vb[j] << " from B" << '\n';
            --j;
        }
        if (i < 0 || vb[j] - va[i] >= 0 && j >= 0) {
            // cout << "Add " << vb[j] << " to B" << '\n';
            B += vb[j];
            --j;
        } else {
            // cout << "Remove " << va[i] << " from A" << '\n';
            --i;
        }
        // cout << "i=" << i << ", j=" << j << '\n';
    }
    return A - B;
}

int main()
{
    int32_t n;
    cin >> n;
    vector<int32_t> va(n), vb(n);
    cin >> va >> vb;
    cout << MaxScoreDiff(va, vb) << '\n';

    return 0;
}   