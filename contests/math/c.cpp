#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        uint64_t n;
        cin >> n;

        while (n % 2 == 0) {
            n = n / 2;
        }

        if (n % 2 == 1 && n > 1) {
            cout << "YES" << '\n';
            continue;
        } 
        bool has_odd_divider = false;
        uint64_t i = 3;
        while (i < sqrt(n) + 1) {
            if (n % i == 0) {
                n = n / i;
                if (i % 2 == 1) {
                    has_odd_divider = true;
                    break;
                }
            } else {
                i += 2;
            }
        }
        cout << (has_odd_divider ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
