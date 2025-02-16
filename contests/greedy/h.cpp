#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int m = n - 1;
        cout << m << '\n';
        for (int i = 0; i < m; ++i) {
            cout << i + 2 << ' ';
        }
        cout << '\n';
        
    }

    return 0;
}