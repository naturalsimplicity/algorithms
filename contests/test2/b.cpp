#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

vector<int32_t> GetOriginalArray(vector<int32_t>& b, int n)
{
    vector<int32_t> a;
    sort(b.begin(), b.end());
    
    int i = 0, step = n - 1;
    while (i < b.size()) {
        a.push_back(b[i]);
        i += step;
        --step;
    }
    a.push_back(b.back());
    return a;
}

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int32_t> b(n * (n - 1) / 2);
        for (int i = 0; i < b.size(); ++i) {
            cin >> b[i];
        }

        cout << GetOriginalArray(b, n) << '\n';
    }

    return 0;
}
