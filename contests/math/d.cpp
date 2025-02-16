#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

template<typename T>
istream& operator>>(istream& in, vector<T>& a)
{
    for (T& x : a) {
        in >> x;
    }
    return in;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        cin >> v;
        set<int> bases;
        for(int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                int base = v[j] - v[i];
                // cout << "i=" << i << ",j=" << j << ",base=" << base << '\n';
                if (!bases.count(base)) {
                    bases.insert(base);
                }
            }
        }
        cout << bases.size() << '\n';
    }
    
    return 0;
}
