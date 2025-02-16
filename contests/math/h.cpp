#include <iostream>
#include <string>
#include <vector>

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
        vector<int> a(n);
        cin >> a;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                cout << a[i+1];
            } else {
                cout << -a[i-1];
            }
            cout << ' ';
        }
        cout << '\n';
        // 1 2  3 4
        // 2 -1 4 -3 
    
    }
    
    return 0;
}
